import std;

std::mutex              mtx;
std::condition_variable cv;
std::queue<int>         items;
// 'done' is only ever read/written while holding mtx, so no std::atomic needed.
bool done = false;

void producer()
{
    for (int i = 1; i <= 5; i++)
    {
        std::lock_guard<std::mutex> lock(mtx);
        items.push(i);
        std::println("Produced {}", i);
        // notify_one wakes one waiter; use notify_all for multiple consumers.
        // Calling notify while holding the lock is safe but may cause a spurious
        // wake-up contention; unlocking before notify can improve throughput.
        cv.notify_one();
    }
    std::lock_guard<std::mutex> lock(mtx);
    done = true;
    cv.notify_one();
}

void consumer()
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        // wait(lock, pred) atomically releases the lock and sleeps until pred is
        // true, protecting against spurious wakeups without an explicit loop.
        cv.wait(lock, [] { return done || !items.empty(); });
        if (items.empty())
        {
            break; // done == true and queue is empty: no more items
        }
        int value = items.front();
        items.pop();
        lock.unlock(); // release lock before printing to reduce contention
        std::println("Consumed {}", value);
    }
}

int main()
{
    std::thread p(producer);
    std::thread c(consumer);
    p.join();
    c.join();
}

import std;

std::atomic<int>  atomic_counter{0};
std::atomic<bool> ready{false};

void increment_atomic(int times)
{
    for (int i = 0; i < times; i++)
    {
        // std::atomic guarantees atomicity (no data race), but does NOT
        // guarantee lock-free on all platforms. Use is_lock_free() to check.
        atomic_counter++;
    }
}

void wait_for_ready()
{
    // ⚠️ Busy-wait (spinlock): wastes CPU cycles and should be avoided in production.
    // This is only for demonstration. Use std::condition_variable, std::binary_semaphore,
    // or std::atomic::wait() (C++20) for efficient thread synchronization.
    while (!ready.load())
    {
        std::this_thread::yield(); // hint the scheduler to run another thread
    }
    std::println("Signal received, ready = true");
}

int main()
{
    // std::atomic increment — correct without std::mutex
    std::thread t1(increment_atomic, 100000);
    std::thread t2(increment_atomic, 100000);
    t1.join();
    t2.join();
    std::println("Atomic counter: {} (std::expected 200000)", atomic_counter.load());

    // std::atomic as a signal flag
    std::thread waiter(wait_for_ready);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    // store() defaults to memory_order_seq_cst (strongest ordering, highest cost).
    // Relaxed or release/acquire ordering can be used for better performance.
    ready.store(true);
    waiter.join();
}

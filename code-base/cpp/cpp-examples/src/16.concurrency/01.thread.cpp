import std;

void worker(int id, int delay_ms)
{
    std::println("Thread {} started", id);
    std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    std::println("Thread {} finished after {}ms", id, delay_ms);
}

int main()
{
    // hardware_concurrency() returns the number of logical CPU cores;
    // use it to guide how many threads to launch in a thread pool.
    std::println("Hardware threads: {}", std::thread::hardware_concurrency());

    // Create threads
    // IMPORTANT: a std::thread that is neither joined nor detached before
    // its destructor runs will call std::terminate() — always join or detach!
    std::thread t1(worker, 1, 200);
    std::thread t2(worker, 2, 100);
    std::thread t3(worker, 3, 150);

    // join() blocks until the thread finishes; use detach() to let a thread
    // run independently (its lifetime is then unmanaged — prefer jthread instead).
    t1.join();
    t2.join();
    t3.join();

    std::println("All threads done");
}

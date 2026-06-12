import std;

int heavy_compute(int n)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    return n * n;
}

int main()
{
    // std::async launches a task asynchronously, returns std::future
    std::future<int> f1 = std::async(std::launch::async, heavy_compute, 10);
    std::future<int> f2 = std::async(std::launch::async, [] { return heavy_compute(20); });

    // Do other work while tasks run in background...
    std::println("Waiting for results...");

    // .get() blocks until the result is ready.
    // If the async task threw an exception, .get() rethrows it here.
    std::println("10² = {}", f1.get());
    std::println("20² = {}", f2.get());

    // std::launch::deferred: task runs lazily on the calling thread when .get()
    // or .wait() is called. No new thread is created — useful for lazy evaluation
    // or when true parallelism is not needed.
    std::future<int> f3 = std::async(std::launch::deferred, heavy_compute, 30);
    std::println("Deferred: 30² = {}", f3.get()); // computed here, on this thread
}

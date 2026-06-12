import std;

// std::barrier (C++20): a reusable synchronization point.
// Threads block until all expected threads have arrived, then all are released.
// A completion function can run each cycle (by one thread, before release).

void phase_worker(int id, auto& barrier)
{
    for (int phase = 1; phase <= 3; ++phase)
    {
        // Simulate work in this phase
        std::this_thread::sleep_for(std::chrono::milliseconds(50 * id));
        std::println("worker {}: phase {} done, waiting at barrier", id, phase);

        // Wait until all threads reach this point
        barrier.arrive_and_wait();
    }
}

int main()
{
    constexpr int num_workers = 3;

    // Completion function: called by one thread each cycle before release
    auto on_completion = [phase = 1]() mutable noexcept
    { std::println("  >>> all threads completed phase {} <<<", phase++); };

    std::barrier barrier{num_workers, on_completion};

    std::println("=== Barrier with Completion Function ===");
    std::vector<std::jthread> workers;
    for (int i = 0; i < num_workers; ++i)
    {
        workers.emplace_back([&, i] { phase_worker(i, barrier); });
    }

    workers.clear(); // join all

    // arrive_and_drop: permanently reduce the expected count
    std::println("\n=== arrive_and_drop ===");
    std::barrier drop_barrier{3};
    std::jthread t1(
        [&]
        {
            std::println("t1: arriving and dropping");
            drop_barrier.arrive_and_drop(); // leaves the barrier permanently
        });
    std::jthread t2(
        [&]
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::println("t2: arriving");
            drop_barrier.arrive_and_wait(); // only needs 2 arrivals now
            std::println("t2: released!");
        });
    std::jthread t3(
        [&]
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::println("t3: arriving");
            drop_barrier.arrive_and_wait();
            std::println("t3: released!");
        });
}
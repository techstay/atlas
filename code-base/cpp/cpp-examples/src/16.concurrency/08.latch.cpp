import std;

// std::latch (C++20): a single-use synchronization primitive.
// Threads block at wait() until the internal counter reaches zero.
// Unlike a barrier, a latch cannot be reused.

void worker(int id, std::latch& start_latch, std::latch& done_latch)
{
    // All threads wait here until the start signal
    start_latch.arrive_and_wait();

    std::println("worker {}: working...", id);
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * id));

    // Signal that this worker is done
    done_latch.count_down();
}

int main()
{
    constexpr int num_workers = 4;

    // start_latch: ensures all threads start simultaneously
    // count = 1 (main thread) + num_workers = 5, all must arrive_and_wait
    std::latch start_latch{num_workers + 1};

    // done_latch: tracks when all workers finish
    std::latch done_latch{num_workers};

    std::println("main: launching {} workers...", num_workers);
    std::vector<std::jthread> workers;
    for (int i = 0; i < num_workers; ++i)
    {
        workers.emplace_back(worker, i, std::ref(start_latch), std::ref(done_latch));
    }

    // Give threads time to reach the latch
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::println("main: releasing start latch!");
    start_latch.count_down(); // all threads + main are now released

    // Wait for all workers to finish
    done_latch.wait();
    std::println("main: all workers done!");

    // std::latch vs std::barrier:
    // - latch: single-use, threads just wait for count to reach zero
    // - barrier: reusable, can execute a completion function each cycle
}
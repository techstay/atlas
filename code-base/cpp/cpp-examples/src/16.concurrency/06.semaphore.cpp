import std;

// counting_semaphore<N>: N is the compile-time upper bound (LeastMaxValue).
// The runtime argument is the initial count (number of permits available).
// std::binary_semaphore is an alias for std::counting_semaphore<1>,
// which works like a lightweight non-recursive mutex.
std::counting_semaphore<3> slots(3); // at most 3 threads may hold a permit at once

void use_resource(int id)
{
    std::println("Thread {} waiting", id);
    slots.acquire();

    std::println("Thread {} acquired", id);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

    std::println("Thread {} released", id);
    slots.release();
}

int main()
{
    std::vector<std::thread> threads;

    for (int i = 1; i <= 5; i++) { threads.emplace_back(use_resource, i); }

    for (auto& t : threads) { t.join(); }
}

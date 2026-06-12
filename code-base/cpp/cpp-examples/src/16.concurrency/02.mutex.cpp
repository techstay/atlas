import std;

std::mutex mtx;
int        counter = 0;

void increment_without_lock(int times)
{
    for (int i = 0; i < times; i++)
    {
        // data race: concurrent read-modify-write is undefined behaviour (UB).
        // The result may be less than, equal to, or even greater than expected.
        counter++;
    }
}

void increment_safe(int times)
{
    for (int i = 0; i < times; i++)
    {
        // lock_guard: lightweight RAII wrapper, locks on construction and unlocks on destruction.
        // For manual unlock or use with condition_variable, use std::unique_lock instead.
        // Finer-grained locking (e.g. locking the whole loop) would reduce contention.
        std::lock_guard<std::mutex> lock(mtx);
        counter++;
    }
}

int main()
{
    // WITHOUT std::mutex — results are unpredictable (data race)
    counter = 0;
    std::thread t1(increment_without_lock, 100000);
    std::thread t2(increment_without_lock, 100000);
    t1.join();
    t2.join();
    std::println("Without std::mutex: {} (expected 200000, but UB — anything is possible)",
                 counter);

    // WITH std::mutex — correct result guaranteed
    counter = 0;
    std::thread t3(increment_safe, 100000);
    std::thread t4(increment_safe, 100000);
    t3.join();
    t4.join();
    std::println("With std::mutex:    {} (expected 200000)", counter);
}

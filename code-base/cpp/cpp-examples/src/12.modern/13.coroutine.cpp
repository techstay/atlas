import std;

// C++23 std::generator — a lazy sequence producer
std::generator<int> fibonacci(int n)
{
    int a = 0, b = 1;
    for (int i = 0; i < n; i++)
    {
        co_yield a; // suspend and emit value
        std::tie(a, b) = std::tuple{b, a + b};
    }
}

std::generator<int> range(int start, int end)
{
    for (int i = start; i < end; i++) { co_yield i; }
}

int main()
{
    // Lazy generation — values are produced on demand
    std::println("Fibonacci (first 10):");
    for (int x : fibonacci(10)) { std::print("{} ", x); }
    std::println();

    // Coroutine std::generator with range
    std::println("Range [5, 10):");
    for (int x : range(5, 10)) { std::print("{} ", x); }
    std::println();

    std::println("\nCoroutines enable lazy, memory-efficient sequences.");
    std::println("Use co_yield to emit values, co_return to finish, co_await to wait.");
}

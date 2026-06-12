import std;

// Naive recursive Fibonacci — exponential time; use only for small n
int fibonacci1(int n)
{
    if (n < 0) { throw std::invalid_argument("n must be non-negative"); }
    if (n == 0) { return 0; }
    if (n == 1) { return 1; }
    return fibonacci1(n - 2) + fibonacci1(n - 1);
}

// Memoized version — cache persists across calls and is not thread-safe
std::int64_t fibonacci2(int n)
{
    if (n < 0) { throw std::invalid_argument("n must be non-negative"); }
    static auto cache = std::vector<std::int64_t>{0, 1};
    if (n < cache.size()) { return cache[n]; }
    cache.push_back(fibonacci2(n - 1) + fibonacci2(n - 2));
    return cache[n];
}

// Iterative version — O(n) time, O(1) space, no shared mutable state
std::int64_t fibonacci3(int n)
{
    if (n < 0) { throw std::invalid_argument("n must be non-negative"); }
    if (n == 0) { return 0; }
    std::int64_t prev{0};
    std::int64_t curr{1};
    for (int i = 2; i <= n; ++i)
    {
        std::int64_t next = prev + curr;
        prev              = curr;
        curr              = next;
    }
    return curr;
}

int main()
{
    // fibonacci1 is intentionally limited to a small n due to exponential cost
    std::println("fibonacci1(5) = {}", fibonacci1(5));
    std::println("fibonacci2(50) = {}", fibonacci2(50));
    std::println("fibonacci3(50) = {}", fibonacci3(50));
}

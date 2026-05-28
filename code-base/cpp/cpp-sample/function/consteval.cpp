#include <functional>
#include <print>

// constexpr functions can be evaluated at compile-time or runtime
constexpr int add(int a, int b)
{
    return a + b;
}

// consteval functions must be evaluated at compile-time only
consteval int minus(int a, int b)
{
    return a - b;
}

int main()
{
    // Both can be executed at compile-time
    std::println("{}", add(3, 5));
    std::println("{}", minus(5, 3));

    // Runtime execution
    int a = 3;
    int b = 5;
    std::println("{}", add(a, b));

    // Compile-time execution
    constexpr int x = 5;
    constexpr int y = 3;
    std::println("{}", minus(x, y));
}

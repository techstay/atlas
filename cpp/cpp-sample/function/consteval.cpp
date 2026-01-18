#include <functional>
#include <print>

// constexpr functions evaluate at compile-time and runtime
constexpr int add(int a, int b)
{
    return a + b;
}

// consteval functions evaluate at compile-time
consteval int minus(int a, int b)
{
    return a - b;
}

int main()
{
    // both can be executed in compile-time
    std::println("{}", add(3, 5));
    std::println("{}", minus(5, 3));

    // execution in runtime
    int a = 3;
    int b = 5;
    std::println("{}", add(a, b));

    // execution in compile-time
    constexpr int x = 5;
    constexpr int y = 3;
    std::println("{}", minus(x, y));
}

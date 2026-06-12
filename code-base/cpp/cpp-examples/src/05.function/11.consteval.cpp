import std;

// constexpr: may run at compile time or runtime depending on arguments
constexpr int add(int a, int b) { return a + b; }

// consteval: must be evaluated at compile time; ill-formed if called with runtime values
consteval int minus(int a, int b) { return a - b; }

// if consteval (C++23): different code paths for compile-time vs runtime evaluation
constexpr int abs_value(int x)
{
    if consteval { return x >= 0 ? x : -x; }
    else
    {
        return std::abs(x);
    }
}

int main()
{
    std::println("add(3, 5) = {}", add(3, 5));
    std::println("minus(5, 3) = {}", minus(5, 3));

    int a = 3;
    int b = 5;
    std::println("add(a, b) at runtime = {}", add(a, b));

    // Does not compile: minus requires constant expressions
    // std::println("{}", minus(a, b));

    constexpr int x = 5;
    constexpr int y = 3;
    std::println("minus(x, y) at compile time = {}", minus(x, y));

    std::println("abs_value(-7) = {}", abs_value(-7));
}

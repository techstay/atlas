import std;

int main()
{
    // Runtime constant: cannot be modified after initialization
    const int I = 100;

    // Compile-time constant: must be known at compile time
    constexpr double PI = 3.1415;

    std::println("I: {}, PI: {}", I, PI);

    // Const reference: binds to a non-const variable without copying
    int        i = 5;
    const int& r = i;
    i            = 10; // OK: modifying the original
    // r            = 10; // Error: r is a const reference
    std::println("i={}, r={}", i, r);

    // Const lvalue reference can also bind to a temporary (rvalue): the
    // temporary's lifetime is extended to match that of the reference.
    // This is the foundation of pass-by-`const&` for read-only parameters.
    const int& temp = 42;
    std::println("const& bound to temporary: {}", temp);

    // constexpr values participate in constant expressions
    constexpr int MAX_COUNT = 100;
    constexpr int MIN_COUNT = -MAX_COUNT;
    static_assert(MAX_COUNT == 100);
    static_assert(-MIN_COUNT == MAX_COUNT);
}

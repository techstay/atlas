import std;

// Trailing return type is required when the return type depends on parameter types
template <typename T, typename U> auto add(T a, U b) -> decltype(a + b) { return a + b; }

// Trailing return type with auto deduction (C++14)
auto multiply(int a, int b) -> int { return a * b; }

// Return type deduced from the trailing type (useful for complex or dependent types)
auto make_pair(int a, double b) -> std::pair<int, double> { return {a, b}; }

int main()
{
    std::println("add(2, 3.5) = {}", add(2, 3.5));
    std::println("multiply(4, 5) = {}", multiply(4, 5));

    auto [i, d] = make_pair(1, 2.5);
    std::println("make_pair: i={}, d={}", i, d);
}

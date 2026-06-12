import std;

// if constexpr: compile-time conditional — the discarded branch is not instantiated.
// Unlike regular if, the condition must be a constant expression.

// Type-based dispatch with if constexpr
template <typename T> auto describe_type(T const& val)
{
    if constexpr (std::is_integral_v<T>) { return std::format("integer: {}", val); }
    else if constexpr (std::is_floating_point_v<T>) { return std::format("float: {:.2f}", val); }
    else if constexpr (std::is_same_v<T, std::string>)
    {
        return std::format("string: \"{}\"", val);
    }
    else
    {
        return std::format("other type");
    }
}

// Recursive variadic template using if constexpr (C++17 style)
template <typename T, typename... Rest> void print_all(T const& first, Rest const&... rest)
{
    std::print("{} ", first);
    if constexpr (sizeof...(rest) > 0)
    {
        print_all(rest...); // only instantiated when rest is non-empty
    }
    else
    {
        std::println(); // base case: no more arguments
    }
}

// if constexpr can replace SFINAE for conditional member functions
template <typename T> class Wrapper
{
    T value;

public:
    Wrapper(T v) : value(v) {}

    void print() const { std::println("value: {}", value); }

    // Only available when T is numeric
    void double_it()
        requires std::integral<T> || std::floating_point<T>
    { value *= 2; }
};

int main()
{
    // Type-based dispatch
    std::println("=== Type Dispatch ===");
    std::println("{}", describe_type(42));
    std::println("{}", describe_type(3.14));
    std::println("{}", describe_type(std::string("hello")));
    std::println("{}", describe_type(std::vector{1, 2, 3}));

    // Recursive variadic with if constexpr
    std::println("\n=== Variadic Print ===");
    print_all(1, 2.5, "three", '4');

    // Conditional member function
    std::println("\n=== Conditional Member ===");
    Wrapper<int> w(21);
    w.double_it(); // OK: int is integral
    w.print();

    // Wrapper<std::string> ws("hello");
    // ws.double_it(); // compile error: string is not numeric
}

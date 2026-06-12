import std;

// Compile-time branch selection
template <typename T> std::string describe(T value)
{
    // Use std::remove_cvref_t (C++20) to decay references and const/volatile qualifiers.
    // Otherwise, const std::string& or int& wouldn't match.
    using DecayedT = std::remove_cvref_t<T>;

    // Note: With 'if constexpr', the branches not taken are discarded.
    // For example, when T is std::string, the compiler discards the 'std::is_integral_v' branch.
    // If it were a regular 'if', std::to_string(value) would fail to compile for std::string.
    if constexpr (std::is_integral_v<DecayedT>) { return "Integer: " + std::to_string(value); }
    else if constexpr (std::is_floating_point_v<DecayedT>)
    {
        return "Float: " + std::to_string(value);
    }
    else if constexpr (std::is_same_v<DecayedT, std::string>) { return "String: " + value; }
    else
    {
        return "Unknown type";
    }
}

// Different implementations based on type
template <typename T> void process(T value)
{
    if constexpr (std::is_arithmetic_v<T>) { std::println("Arithmetic value: {}", value); }
    else
    {
        std::println("Non-arithmetic value");
    }
}

int main()
{
    std::println("{}", describe(42));
    std::println("{}", describe(3.14));
    std::println("{}", describe(std::string("hello")));

    process(100);
    process(3.14);
    process(std::string("test"));
}

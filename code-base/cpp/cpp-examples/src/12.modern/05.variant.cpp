import std;

// Variant can hold different types
using Value = std::variant<int, double, std::string>;

// Helper struct for std::visit overloaded lambdas (C++17/20)
template <class... Ts> struct overloaded : Ts...
{
    using Ts::operator()...;
};

void print_value(const Value& v)
{
    // std::visit with overloaded lambdas
    std::visit(
        overloaded{
            [](int arg) { std::println("Value (int): {}", arg); },
            [](double arg) { std::println("Value (double): {}", arg); },
            [](const std::string& arg) { std::println("Value (string): {}", arg); },
        },
        v);
}

int main()
{
    // Basic std::variant usage
    Value v1{42};
    Value v2{3.14};
    Value v3{"hello"};

    print_value(v1);
    print_value(v2);
    print_value(v3);

    // Check which type is held
    std::println("v1 is int: {}", std::holds_alternative<int>(v1));
    std::println("v2 is double: {}", std::holds_alternative<double>(v2));

    // Get value with type
    std::println("v1 as int: {}", get<int>(v1));

    // Variant in container
    std::vector<Value> values{1, 2.5, "world"};
    for (const auto& v : values) { print_value(v); }

    // Index of current type
    std::println("v1 index: {}", v1.index());
}

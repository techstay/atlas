import std;

int main()
{
    // std::variant — type-safe union
    using VarType =
        std::variant<std::monostate, int, std::string, double>; // monostate = empty state
    VarType var; // default-initialized to std::monostate
    std::println("var.index(): {}", var.index());
    std::println("holds monostate: {}", std::holds_alternative<std::monostate>(var));

    var = 42;
    std::println("var is int: {}", std::holds_alternative<int>(var));
    std::println("var value: {}", std::get<int>(var));

    var = "World"; // const char* converts to std::string
    std::println("var value: {}", std::get<std::string>(var));

    // std::visit — apply a visitor to the active alternative
    std::visit(
        [](const auto& value)
        {
            using T = std::decay_t<decltype(value)>;
            if constexpr (std::is_same_v<T, std::monostate>) { std::println("Visited: monostate"); }
            else
            {
                std::println("Visited: {}", value);
            }
        },
        var);

    // std::get_if — returns pointer or nullptr
    var = 3.14;
    if (const double* d = std::get_if<double>(&var)) { std::println("get_if<double>: {}", *d); }
}

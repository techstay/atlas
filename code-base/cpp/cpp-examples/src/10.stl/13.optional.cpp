import std;

int main()
{
    // std::optional — a value that may or may not be present
    std::optional<int> opt_int; // initialized to std::nullopt
    std::println("opt_int.has_value(): {}", opt_int.has_value());
    std::println("opt_int.value_or(42): {}", opt_int.value_or(42));

    opt_int = 10;
    std::println("opt_int.has_value(): {}", opt_int.has_value());
    std::println("opt_int.value(): {}", opt_int.value());
    std::println("*opt_int: {}", *opt_int);

    std::optional<std::string> opt_str{"Hello"};
    std::println("opt_str->size(): {}", opt_str->size());
    opt_str.reset(); // reset to empty
    std::println("opt_str after reset: {}", opt_str.value_or("Empty"));
}

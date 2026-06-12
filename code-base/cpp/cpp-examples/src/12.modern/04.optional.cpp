import std;

// Function that may or may not return a value
std::optional<int> find_first_even(const std::vector<int>& nums)
{
    for (auto n : nums)
    {
        if (n % 2 == 0) { return n; }
    }
    return std::nullopt;
}

// Function returning std::optional std::string
std::optional<std::string> get_name(int id)
{
    if (id == 1) { return "Alice"; }
    if (id == 2) { return "Bob"; }
    return std::nullopt;
}

int main()
{
    std::vector<int> nums{1, 3, 5, 8, 9};

    // Check if std::optional has value
    auto result = find_first_even(nums);
    if (result) { std::println("Found even: {}", *result); }

    // Use std::value_or for default
    auto name = get_name(99);
    std::println("Name: {}", name.value_or("Unknown"));

    // Transform std::optional using C++23 monadic operations
    auto doubled = find_first_even(nums).transform([](int x) { return x * 2; });
    if (doubled) { std::println("Doubled: {}", *doubled); }

    // Optional with no value
    auto empty = std::optional<int>{};
    std::println("Has value: {}", empty.has_value());
}

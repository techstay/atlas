import std;

int main()
{
    // Create a std::string instance
    std::string s("Hello world!");

    // Count character types using STL ranges algorithms (C++20)
    const auto alpha_count =
        std::ranges::count_if(s, [](unsigned char c) { return std::isalpha(c); });
    const auto digit_count =
        std::ranges::count_if(s, [](unsigned char c) { return std::isdigit(c); });
    const auto space_count =
        std::ranges::count_if(s, [](unsigned char c) { return std::isspace(c); });
    const auto punct_count =
        std::ranges::count_if(s, [](unsigned char c) { return std::ispunct(c); });

    std::println("alpha_count:{}, digit_count:{}, space_count:{}, punct_count:{}", alpha_count,
                 digit_count, space_count, punct_count);

    // C++20 std::starts_with and std::ends_with examples
    std::println("\nC++20 string checking examples:");
    if (s.starts_with("Hel")) { std::println("\"{}\" starts with \"Hel\"", s); }
    if (s.ends_with("!")) { std::println("\"{}\" ends with \"!\"", s); }
    if (!s.starts_with("World")) { std::println("\"{}\" does NOT start with \"World\"", s); }
}

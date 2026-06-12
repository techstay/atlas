import std;

int main()
{
    using namespace std::string_literals;
    using namespace std::string_view_literals;

    // 's' suffix creates std::string from literal
    auto hello = "Hello"s;
    std::println("std::string:   '{}' (type has length method: {})", hello, hello.length());

    // 'sv' suffix creates std::string_view from literal
    auto world = "World"sv;
    std::println("string_view:   '{}' (length: {})", world, world.length());

    // Without the suffix, string literals are const char[]
    auto raw = "hello"; // const char[6], not std::string
    static_assert(!std::is_same_v<decltype(raw), std::string>);

    // String concatenation with 's'
    auto combined = "Hello, "s + "World"s + "!"s;
    std::println("Combined: '{}'", combined);

    // Multi-line string literals (C++17)
    auto multi = R"(Line 1
Line 2
Line 3)"s;
    std::println("Multi-line:\n{}", multi);
}

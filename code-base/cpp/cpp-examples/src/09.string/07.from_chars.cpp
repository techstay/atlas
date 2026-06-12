import std;

// std::from_chars / std::to_chars (C++17): fast, locale-independent,
// non-allocating number ↔ string conversion. Unlike std::stoi/std::to_string,
// these do not throw exceptions and do not allocate memory.

int main()
{
    // =============================
    // std::from_chars: string → number
    // =============================
    std::println("=== std::from_chars (parse) ===");

    // Integer parsing
    auto parse_and_print = [](std::string_view sv)
    {
        int value;
        auto [ptr, ec] = std::from_chars(sv.data(), sv.data() + sv.size(), value);
        if (ec == std::errc{}) { std::println("  '{}' → {} (remaining: '{}')", sv, value, ptr); }
        else
        {
            std::println("  '{}' → parse error: {}", sv, std::make_error_code(ec).message());
        }
    };

    parse_and_print("42");
    parse_and_print("-123");
    parse_and_print("3.14"); // stops at '.', parses 3
    parse_and_print("abc");  // no digits at all

    // Parsing with different bases
    std::println("\n=== Different Bases ===");
    auto parse_hex = [](std::string_view sv)
    {
        int value;
        auto [ptr, ec] = std::from_chars(sv.data(), sv.data() + sv.size(), value, 16);
        if (ec == std::errc{}) { std::println("  hex '{}' → {}", sv, value); }
    };
    parse_hex("FF");
    parse_hex("dead");
    parse_hex("7FFFFFFF");

    // Floating-point parsing (C++17 for integers, full float support varies)
    std::println("\n=== Floating-Point Parsing ===");
    auto parse_double = [](std::string_view sv)
    {
        double value;
        auto [ptr, ec] = std::from_chars(sv.data(), sv.data() + sv.size(), value);
        if (ec == std::errc{}) { std::println("  '{}' → {}", sv, value); }
        else
        {
            std::println("  '{}' → parse error", sv);
        }
    };
    parse_double("3.14159");
    parse_double("1.5e10");
    parse_double("-0.5");

    // =============================
    // std::to_chars: number → string
    // =============================
    std::println("\n=== std::to_chars (format) ===");

    char buf[64];

    // Integer formatting
    auto format_int = [&](int n)
    {
        auto [ptr, ec] = std::to_chars(buf, buf + sizeof(buf), n);
        *ptr           = '\0';
        std::println("  {} → \"{}\"", n, buf);
    };
    format_int(42);
    format_int(-123);
    format_int(0);

    // Integer with base
    std::println("\n=== Integer with Base ===");
    auto [ptr, _] = std::to_chars(buf, buf + sizeof(buf), 255, 16);
    *ptr          = '\0';
    std::println("  255 in hex → \"{}\"", buf);

    std::to_chars(buf, buf + sizeof(buf), 255, 2);
    buf[ptr - buf] = '\0';
    std::println("  255 in binary → \"{}\"", buf);

    // Floating-point formatting
    std::println("\n=== Floating-Point Formatting ===");
    auto format_double = [&](double n)
    {
        auto [p, ec] = std::to_chars(buf, buf + sizeof(buf), n);
        *p           = '\0';
        std::println("  {} → \"{}\"", n, buf);
    };
    format_double(3.14159);
    format_double(1.5e10);

    // Precision control
    auto [p2, ec2] =
        std::to_chars(buf, buf + sizeof(buf), std::numbers::pi, std::chars_format::fixed, 4);
    *p2 = '\0';
    std::println("  pi (fixed, 4dp) → \"{}\"", buf);
}

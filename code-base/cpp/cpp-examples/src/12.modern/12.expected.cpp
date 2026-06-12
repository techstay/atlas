import std;

using namespace std::string_literals;

// std::expected (C++23) — like std::optional but carries an error value
std::expected<int, std::string> safe_divide(int a, int b)
{
    if (b == 0) { return std::unexpected{"division by zero"s}; }
    return a / b;
}

std::expected<int, std::string> parse_int(std::string_view s)
{
    try
    {
        return std::stoi(std::string(s));
    }
    catch (...)
    {
        return std::unexpected{std::format("cannot parse '{}'", s)};
    }
}

int main()
{
    // Successful case
    auto r1 = safe_divide(10, 2);
    if (r1) { std::println("10 / 2 = {}", *r1); }

    // Error case
    auto r2 = safe_divide(10, 0);
    if (!r2) { std::println("Error: {}", r2.error()); }

    // std::value_or — provide a fallback
    std::println("fallback: {}", safe_divide(6, 0).value_or(-1));

    // and_then / or_else — monadic operations (C++23)
    // .transform() — map the success value (infallible operation)
    auto r3 = parse_int("42").transform([](int n) { return n * 2; });
    std::println("transform (double): {}", *r3);

    // .and_then() — chain a fallible operation (returns std::expected)
    auto r4 = parse_int("10").and_then([](int n) -> std::expected<int, std::string>
                                       { return safe_divide(100, n); });
    std::println("and_then (100 / 10): {}", *r4);

    // .or_else() — handle the error, possibly recovering
    auto r5 = parse_int("abc").or_else(
        [](const std::string& err) -> std::expected<int, std::string>
        {
            std::println("or_else: recovering from '{}'", err);
            return 0; // fallback value
        });
    std::println("or_else (recovered): {}", *r5);

    auto r6 = parse_int("abc");
    if (!r6) { std::println("Parse error: {}", r6.error()); }
}

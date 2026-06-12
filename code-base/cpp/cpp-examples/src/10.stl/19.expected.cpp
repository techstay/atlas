import std;

using namespace std::string_literals;

// std::expected<T, E> (C++23): either a value of type T or an error of type E.
// Like std::optional but carries an error value instead of just "empty".

std::expected<double, std::string> safe_sqrt(double x)
{
    if (x < 0)
    {
        return std::unexpected{std::format("cannot compute sqrt({}): negative input", x)};
    }
    return std::sqrt(x);
}

std::expected<int, std::string> parse_int(std::string_view s)
{
    int value;
    auto [ptr, ec] = std::from_chars(s.data(), s.data() + s.size(), value);
    if (ec == std::errc{}) { return value; }
    return std::unexpected{std::format("failed to parse '{}'", s)};
}

int main()
{
    // Basic usage: check with if (exp) or if (!exp)
    std::println("=== Basic Usage ===");
    auto r1 = safe_sqrt(16.0);
    if (r1) { std::println("sqrt(16) = {}", *r1); }

    auto r2 = safe_sqrt(-4.0);
    if (!r2) { std::println("error: {}", r2.error()); }

    // value_or — provide a fallback for errors
    std::println("\n=== value_or ===");
    std::println("sqrt(25)  = {}", safe_sqrt(25.0).value_or(-1.0));
    std::println("sqrt(-9)  = {}", safe_sqrt(-9.0).value_or(-1.0));

    // Monadic operations (C++23)
    std::println("\n=== Monadic Operations ===");

    // .transform() — map the success value (infallible)
    auto r3 = parse_int("42").transform([](int n) { return n * 2; });
    std::println("transform: {}", *r3);

    // .and_then() — chain a fallible operation
    auto r4 = parse_int("100").and_then(
        [](int n) -> std::expected<int, std::string>
        {
            if (n > 50) { return std::unexpected{"value too large"s}; }
            return n;
        });
    if (!r4) { std::println("and_then error: {}", r4.error()); }

    // .or_else() — handle the error, possibly recover
    auto r5 = parse_int("abc").or_else(
        [](const std::string& err) -> std::expected<int, std::string>
        {
            std::println("or_else: recovering from '{}'", err);
            return 0; // fallback
        });
    std::println("or_else recovered: {}", *r5);

    // .error_or — get the error or a default
    std::println("\n=== error_or ===");
    auto r6 = parse_int("123");
    std::println("error_or: '{}'", r6.error_or("no error"s));
}

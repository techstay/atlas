import std;

// When to use least vs fast vs fixed-width types:
// - int_leastN_t: smallest type with ≥ N bits — use when minimizing memory
// - int_fastN_t:  fastest type with ≥ N bits — use when maximizing speed
// - intN_t:       exactly N bits — use when exact width matters (e.g., protocols)

int main()
{
    // Sizes on this platform
    std::println("=== Sizes on this platform ===");
    std::println("least 8:  {} bits", sizeof(std::int_least8_t) * 8);
    std::println("least 16: {} bits", sizeof(std::int_least16_t) * 8);
    std::println("least 32: {} bits", sizeof(std::int_least32_t) * 8);
    std::println();
    std::println("fast 8:  {} bits", sizeof(std::int_fast8_t) * 8);
    std::println("fast 16: {} bits", sizeof(std::int_fast16_t) * 8);
    std::println("fast 32: {} bits", sizeof(std::int_fast32_t) * 8);

    // Practical example: choosing the right type
    // For a large array where memory matters, use least types:
    std::println("\n=== Memory-sensitive: int_least16_t array ===");
    std::vector<std::int_least16_t> temperatures = {23, 19, 31, 27, 22};
    auto sum = std::accumulate(temperatures.begin(), temperatures.end(), 0);
    std::println("avg temperature: {}", sum / static_cast<int>(temperatures.size()));

    // For a loop counter where speed matters, use fast types:
    std::println("\n=== Performance-sensitive: int_fast32_t loop ===");
    std::int_fast32_t total = 0;
    for (std::int_fast32_t i = 0; i < 1000000; ++i) { total += i % 2; }
    std::println("total: {}", total);

    // Compare with fixed-width: exact size, portable across platforms
    std::println("\n=== Fixed-width: int32_t (exactly 32 bits) ===");
    std::println("int32_t: {} bits", sizeof(std::int32_t) * 8);
    std::println("int32_t max: {}", std::numeric_limits<std::int32_t>::max());
}

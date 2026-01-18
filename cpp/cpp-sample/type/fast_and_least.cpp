#include <cstdint>
#include <print>

int main()
{
    // Least types: smallest integer type with at least specified width
    std::println("least 8:  {} bits", sizeof(std::int_least8_t) * 8);
    std::println("least 16: {} bits", sizeof(std::int_least16_t) * 8);
    std::println("least 32: {} bits", sizeof(std::int_least32_t) * 8);
    std::println("");

    // Fast types: fastest integer type with at least specified width
    std::println("fast 8:  {} bits", sizeof(std::int_fast8_t) * 8);
    std::println("fast 16: {} bits", sizeof(std::int_fast16_t) * 8);
    std::println("fast 32: {} bits", sizeof(std::int_fast32_t) * 8);

    return 0;
}
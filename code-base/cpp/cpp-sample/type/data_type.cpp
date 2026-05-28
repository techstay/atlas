#include <climits>
#include <cstdint>
#include <print>
#include <string>

using namespace std;

int main()
{
    // Fundamental integer types with different sizes
    short s      = 600;
    int i        = 1'000;
    long l       = 1'000L;
    long long ll = 1'000LL;

    // Signed and unsigned variants
    signed int si   = -1'000;
    unsigned int ui = 1'000U;

    // Boolean type
    bool b = true && false;

    // Floating-point types with different precision
    float f        = 3.5F;
    double d       = 3.5;
    long double ld = 3.1415L;

    // Character types for different character encodings
    char c       = 'c';
    wchar_t wc   = 'c';
    char8_t c8   = 'c';
    char16_t c16 = 'c';
    char32_t c32 = 'c';

    // String literals with automatic line continuation
    char str[]         = "abc";
    char long_string[] = "This is a long line "
                         "and next line";

    // Platform-specific type limits from <climits>
    std::println("INT_MAX: {}", INT_MAX);
    std::println("SHORT_MIN: {}", SHRT_MIN);
    std::println("ULONG_MAX: {}", ULONG_MAX);
}

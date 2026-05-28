#include <print>

using namespace std;

int main()
{
    // Integer literals with type suffixes
    unsigned int ui        = 1'000U;
    long l                 = 1'000L;
    unsigned long ul       = 10'000UL;
    long long ll           = 1'000LL;
    unsigned long long ull = 100'000ULL;

    // Octal literal (prefix 0)
    auto octal = 01234567;

    // Hexadecimal literal (prefix 0x)
    auto hex = 0xcafe;

    // Binary literal with digit separator (C++14)
    auto binary = 0b1010'1100;

    // Floating-point literals with type suffixes
    float f        = 10.0F;
    long double ld = 200.0L;

    // Scientific notation for floating-point
    double pi100 = 3.1415E2;

    // User-defined literals for string types (C++14)
    string s       = "abc"s;
    string_view sv = "abc"sv;

    println("{}", sv);
}

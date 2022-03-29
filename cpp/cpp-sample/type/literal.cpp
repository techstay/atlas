#include <iostream>

using namespace std;

int main()
{
    unsigned int ui        = 1'000U;
    long l                 = 1'000L;
    unsigned long ul       = 10'000UL;
    long long ll           = 1'000LL;
    unsigned long long ull = 100'000ULL;

    // octal
    auto octal = 01234567;

    // hexadecimal
    auto hex = 0xcafe;
    // binary
    // digit separator, since c++14
    auto binary = 0b1010'1100;

    float f        = 10.0F;
    long double ld = 200.0L;

    // scientific notions
    double pi100 = 3.1415E2;

    string s       = "abc"s;
    string_view sv = "abc"sv;
}

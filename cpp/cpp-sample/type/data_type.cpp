#include <climits>
#include <cstdint>
#include <print>
#include <string>

using namespace std;

int main()
{
    // 整型
    short s      = 600;
    int i        = 1'000;
    long l       = 1'000L;
    long long ll = 1'000LL;

    // 有符号和无符号
    signed int si   = -1'000;
    unsigned int ui = 1'000U;

    // bool
    bool b = true && false;

    // 浮点型
    float f        = 3.5F;
    double d       = 3.5;
    long double ld = 3.1415L;

    // 字符和字符型字面量
    char c       = 'c';
    wchar_t wc   = 'c';
    char8_t c8   = 'c';
    char16_t c16 = 'c';
    char32_t c32 = 'c';

    char str[]         = "abc";
    char long_string[] = "This is a long line "
                         "and next line";

    // 数据类型的大小
    std::println("INT_MAX: {}", INT_MAX);
    std::println("SHORT_MIN: {}", SHRT_MIN);
    std::println("ULONG_MAX: {}", ULONG_MAX);
}

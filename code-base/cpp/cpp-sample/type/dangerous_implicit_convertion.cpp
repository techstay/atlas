#include <print>

using namespace std;

int main()
{
    int a{-1};
    unsigned int b{1};

    // -1 is implicitly converted to UINT_MAX (4294967295 on 32-bit)
    // due to unsigned integer promotion, making the comparison false
    if (a < b)
    {
        std::println("-1 < 1 is true");
    }
    else
    {
        std::println("something goes wrong");
    }
}
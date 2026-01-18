#include <print>

using namespace std;

int main()
{
    int a{-1};
    unsigned int b{1};

    // -1 is implicitly converted to a large number
    // so the expression is false
    if (a < b)
    {
        std::println("-1 < 1 is true");
    }
    else
    {
        std::println("something goes wrong");
    }
}
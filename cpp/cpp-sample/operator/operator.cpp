#include <print>

using namespace std;

int main()
{
    // sizeof operator
    auto array = {1, 2, 3, 4, 5};
    std::println("size of array:{}", sizeof(array));

    // comma operator, the value of the expression is the right-hand operhand
    auto i = (3, 4);
    std::println("the value of comma expression is {}", i);
}
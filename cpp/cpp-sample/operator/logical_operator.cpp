#include <print>

using namespace std;

int main()
{
    // 逻辑运算符
    bool result;

    result = true && false;
    result = true || false;
    result = !true;

    // short circuit
    int i = 0;

    result = false && (i++);
    std::println("Check if i is still 0: {}", i);

    result = true || (i++);
    std::println("Check if i is still 0: {}", i);

    // no short circuit
    result = true && (i++);
    std::println("Check if i is still 0: {}", i);
}

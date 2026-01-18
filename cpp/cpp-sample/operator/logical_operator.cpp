#include <print>

using namespace std;

int main()
{
    // Logical operators
    bool result;

    result = true && false;
    result = true || false;
    result = !true;

    // Short circuit evaluation
    int i = 0;

    result = false && (i++);
    std::println("Check if i is still 0: {}", i);

    result = true || (i++);
    std::println("Check if i is still 0: {}", i);

    // no short circuit
    result = true && (i++);
    std::println("Check if i is still 0: {}", i);
}

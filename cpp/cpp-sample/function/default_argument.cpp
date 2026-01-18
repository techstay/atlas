#include <print>

using namespace std;

// Default parameters should be placed at the end of the parameter list
void printTwo(int a, int b = 0)
{
    std::println("a={}, b={}", a, b);
}

int main()
{
    printTwo(3);
    printTwo(3, 4);
}

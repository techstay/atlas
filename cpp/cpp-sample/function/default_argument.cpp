#include <print>

using namespace std;

// the default parameter should be placed at the end
void printTwo(int a, int b = 0)
{
    std::println("a={}, b={}", a, b);
}

int main()
{
    printTwo(3);
    printTwo(3, 4);
}

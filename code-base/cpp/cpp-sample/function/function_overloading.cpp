#include <print>

using namespace std;

int sum(int a, int b)
{
    std::println("int sum");
    return a + b;
}

double sum(double a, double b)
{
    std::println("double sum");
    return a + b;
}

int main()
{
    std::println("{}", sum(2, 3));
    std::println("{}", sum(3.0, 4.0));
    std::println("{}", sum(static_cast<double>(3), 100.0));
}

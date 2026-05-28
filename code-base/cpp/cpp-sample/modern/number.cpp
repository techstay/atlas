#include <numbers>
#include <print>

// std::numbers is available in C++20
int main()
{
    using namespace std::numbers;

    std::println("pi:\t{}", pi);
    std::println("e:\t{}", e);
    std::println("ln2:\t{}", ln2);
    std::println("ln10:\t{}", ln10);
    std::println("sqrt2:\t{}", sqrt2);
}

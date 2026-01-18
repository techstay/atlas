#include <print>

using namespace std;

int main(int argc, const char **argv)
{
    // Runtime constant: value cannot be modified after initialization
    const int I = 100;

    // Compile-time constant: value must be known at compile time
    constexpr double PI = 3.1415;

    println("I: {}, PI: {}", I, PI);
    return 0;
}

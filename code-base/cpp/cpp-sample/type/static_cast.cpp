#include <print>

using namespace std;

int main(int argc, const char **argv)
{
    int i = 1'000;
    double d{};

    // Implicit conversion: int to double
    d = i;
    std::println("{}", d);

    // Explicit type conversion using static_cast
    d = static_cast<double>(i);
    std::println("{}", d);

    return 0;
}

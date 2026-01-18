#include <print>

using namespace std;

int main(int argc, const char **argv)
{
    int i = 1'000;
    double d{};

    // implicit cast
    d = i;
    std::println("{}", d);

    // explicit cast
    d = static_cast<double>(i);
    std::println("{}", d);

    return 0;
}
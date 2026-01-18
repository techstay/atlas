#include <print>

using namespace std;

int main()
{
    // Declare without initialization
    // The value is undetermined (undefined behavior)
    int x;
    std::println("{}", x);

    // Zero initialization
    int y{};
    std::println("{}", y);
}
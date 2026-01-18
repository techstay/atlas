#include <print>

using namespace std;

int main()
{
    // incrementing
    auto i{0};
    // i++ first returns i and then increments
    std::println("{}", i++);
    // ++i first increments and returns the incremented value
    std::println("{}", ++i);

    std::println("{}", --i);
    std::println("{}", i--);
}

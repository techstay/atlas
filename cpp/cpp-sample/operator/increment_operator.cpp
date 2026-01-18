#include <print>

using namespace std;

int main()
{
    // incrementing
    auto i{0};
    // i++ first returns i and then increments
    std::println("{}", i++);
    // ++i first increments and return the value that has incremented
    std::println("{}", ++i);

    std::println("{}", --i);
    std::println("{}", i--);
}

#include <print>

using namespace std;

void increment_and_print()
{
    // Static local variables are initialized only once when declared
    // Their lifetime lasts for the entire program duration
    static int count{0};
    std::println("{}", ++count);
}

int main()
{
    increment_and_print();
    increment_and_print();
    increment_and_print();
}

#include <print>

using namespace std;

void increment_and_print()
{
    // static variables are initialized once when declared
    // the duration of static local variables begins and ends with the program
    static int count{0};
    std::println("{}", ++count);
}

int main()
{
    increment_and_print();
    increment_and_print();
    increment_and_print();
}

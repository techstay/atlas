#include <print>

using namespace std;

// global variables
int i{10'000};

int main()
{
    std::println("global variable:{}", i);

    // shadowing global variables
    int i{1};
    std::println("local variable:{}", i);

    // global namespace
    std::println("using global namespace:{}", ::i);
}

#include <print>

using namespace std;

// Global variables
int i{10'000};

int main()
{
    std::println("global variable:{}", i);

    // Local variable shadows the global variable
    int i{1};
    std::println("local variable:{}", i);

    // Global namespace
    std::println("using global namespace:{}", ::i);
}

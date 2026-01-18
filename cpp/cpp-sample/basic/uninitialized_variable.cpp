#include <print>

using namespace std;

int main()
{
    // declaring and not initializing the value
    // which is undetermined
    int x;
    std::println("{}", x);

    // zero initialization
    int y{};
    std::println("{}", y);
}
#include <print>

using namespace std;

int main()
{
    auto i = 0;
    while (i <= 10)
    {
        std::print("{} ", i);
        i++;
    }
    std::println("");

    // intentional infinite loops
    i = 0;
    while (true)
    {
        if (i % 10 == 0)
        {
            break;
        }
        i++;
    }
    std::println("infinite loop ends.");

    // do while
    do
    {
        if (i % 10 == 0)
        {
            break;
        }
        i++;
    } while (true);

    std::println("infinite loop ends.");
}

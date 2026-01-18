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

    // Intentional infinite loop
    i = 0;
    while (true)
    {
        if (i % 10 == 0)
        {
            break;
        }
        i++;
    }
    std::println("Infinite loop ends.");

    // Do-while loop
    do
    {
        if (i % 10 == 0)
        {
            break;
        }
        i++;
    } while (true);

    std::println("Infinite loop ends.");
}

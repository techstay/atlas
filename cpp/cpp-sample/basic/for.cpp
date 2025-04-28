#include <print>

int main()
{
    for (auto i = 0; i <= 5; i++)
    {
        std::print("{} ", i);
    }
    std::println("");

    // infinite loops
    auto i = 0;
    for (;;)
    {
        if (i == 5)
        {
            break;
        }
        i++;
    }
    std::println("infinite loop ends.");
}

#include <print>

int main()
{
    for (auto i = 0; i <= 5; i++)
    {
        std::print("{} ", i);
    }
    std::println("");

    // Infinite loop
    auto i = 0;
    for (;;)
    {
        if (i == 5)
        {
            break;
        }
        i++;
    }
    std::println("Infinite loop ends.");
}

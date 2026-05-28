#include <print>

using namespace std;

int main()
{
    // Break statement
    for (auto i{0}; i <= 10; i++)
    {
        if (i == 5)
        {
            break;
        }
        print("{} ", i);
    }
    println();

    // Continue statement
    for (auto i{0}; i <= 10; i++)
    {
        if (i == 5)
        {
            // Skip the value 5
            continue;
        }
        print("{} ", i);
    }
    println();
}

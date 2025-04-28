#include <print>
using namespace std;

int main()
{
    auto i{0};
    // simulating for loop using goto
START:
    if (i <= 5)
    {
        i++;
        goto START;
    }
    else
    {
        println("now i is {}", i);
        println("never use goto!");
    }
}

#include <print>

// Macros perform simple text replacement
// and may cause unexpected results
#define ADD(a, b) a + b

// Safe version with parentheses
#define SAFE_ADD(a, b) (a + b)

int main()
{
    using namespace std;
    // Expected 16, but got 13 instead
    std::println("{}", ADD(3, 5) * 2);
    // Adding parentheses makes it work correctly
    std::println("{}", SAFE_ADD(3, 5) * 2);
}

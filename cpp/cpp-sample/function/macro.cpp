#include <print>

// the macro replaces texts roughly,
// and may cause unexpected results
#define ADD(a, b) a + b

// safe way
#define SAFE_ADD(a, b) (a + b)

int main()
{
    using namespace std;
    // expected to be 16, but was 13 instead
    std::println("{}", ADD(3, 5) * 2);
    // adding parentheses makes it work properly
    std::println("{}", SAFE_ADD(3, 5) * 2);
}

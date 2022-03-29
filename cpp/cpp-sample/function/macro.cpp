#include <iostream>

// the macro replaces texts roughly,
// and may cause unexpected results
#define ADD(a, b) a + b

// safe way
#define SAFE_ADD(a, b) (a + b)

int main()
{
    using namespace std;
    // expected to be 16, but was 13 instead
    cout << ADD(3, 5) * 2 << endl;
    // adding parentheses makes it work properly
    cout << SAFE_ADD(3, 5) * 2 << endl;
}

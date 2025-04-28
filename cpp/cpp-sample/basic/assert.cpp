#include <cassert>

using namespace std;

int main()
{
    auto i = 5;
    // asserting i==5
    assert(i == 5);

    // the program will fail when asserting fails
    assert(i % 2 == 0);
}

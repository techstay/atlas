#include <cassert>

using namespace std;

int main()
{
    auto i = 5;
    // Assert that i equals 5
    assert(i == 5);

    // The program will terminate when the assertion fails
    assert(i % 2 == 0);
}

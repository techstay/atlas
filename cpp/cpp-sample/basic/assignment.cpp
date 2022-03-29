#include <iostream>

using namespace std;

int main()
{
    // copy initialization
    int a = 5;

    // direct initialization
    int b(10);

    // list initialization, the preferred way
    int c{2};

    // zero initialization
    // maybe_unused attributes are used for suppress warnings for unused variables
    [[maybe_unused]] int d{};
}
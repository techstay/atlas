#include <iostream>

using namespace std;

int main()
{
    // declaring and not initializing the value
    // which is undetermined
    int x;
    cout << x << endl;

    // zero initialization
    int y{};
    cout << y << endl;
}
#include <iostream>

using namespace std;

// the default parameter should be placed at the end
void printTwo(int a, int b = 0)
{
    cout << "a=" << a << ", "
         << "b=" << b << endl;
}

int main()
{
    printTwo(3);
    printTwo(3, 4);
}

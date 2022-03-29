#include <iostream>

using namespace std;

int main()
{
    // sizeof operator
    auto array = {1, 2, 3, 4, 5};
    cout << "size of array:" << sizeof(array) << endl;

    // comma operator, the value of the expression is the right-hand operhand
    auto i = (3, 4);
    cout << "the value of comma expression is " << i << endl;
}
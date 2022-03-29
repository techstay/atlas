#include <iostream>

using namespace std;

int main()
{
    // 逻辑运算符
    bool result;

    result = true && false;
    result = true || false;
    result = !true;

    // short circuit
    int i = 0;

    result = false && (i++);
    cout << "Check if i is still 0: " << i << endl;

    result = true || (i++);
    cout << "Check if i is still 0: " << i << endl;

    // no short circuit
    result = true && (i++);
    cout << "Check if i is still 0: " << i << endl;
}

#include <iostream>

using namespace std;

int main()
{
    // incrementing
    auto i{0};
    // i++ first returns i and then increments
    cout << i++ << endl;
    // ++i first increments and return the value that has incremented
    cout << ++i << endl;

    cout << --i << endl;
    cout << i-- << endl;
}

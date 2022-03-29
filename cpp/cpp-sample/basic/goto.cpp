#include <iostream>

using namespace std;

int main()
{
    auto i{0};
    // simulating for loop using goto
START:
    if (i <= 5)
    {
        i++;
        goto START;
    }
    else
    {
        cout << "now i is " << i << endl;
        cout << "never use goto!" << endl;
    }
}

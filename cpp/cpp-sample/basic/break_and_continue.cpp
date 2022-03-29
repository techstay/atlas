#include <iostream>

using namespace std;

int main()
{
    // break
    for (auto i{0}; i <= 10; i++)
    {
        if (i == 5)
        {
            break;
        }
        cout << i << " ";
    }
    cout << endl;

    // continue
    for (auto i{0}; i <= 10; i++)
    {
        if (i == 5)
        {
            // skip the value 5
            continue;
        }
        cout << i << " ";
    }
    cout << endl;
}

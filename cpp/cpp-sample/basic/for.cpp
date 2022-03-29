#include <iostream>

using namespace std;

int main()
{
    for (auto i = 0; i <= 5; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    // infinite loops
    auto i = 0;
    for (;;)
    {
        if (i == 5)
        {
            break;
        }
        i++;
    }
    cout << "infinite loop ends." << endl;
}

#include <iostream>

using namespace std;

int main()
{
    auto i = 0;
    while (i <= 10)
    {
        cout << i << " ";
        i++;
    }
    cout << endl;

    // intentional infinite loops
    i = 0;
    while (true)
    {
        if (i % 10 == 0)
        {
            break;
        }
        i++;
    }
    cout << "infinite loop ends." << endl;

    // do while
    do
    {
        if (i % 10 == 0)
        {
            break;
        }
        i++;
    } while (true);

    cout << "infinite loop ends." << endl;
}

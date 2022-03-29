#include <iostream>

using namespace std;

int main()
{
    int array[]{1, 2, 3, 4, 5};

    for (const auto &e : array)
    {
        cout << e << " ";
    }
    cout << endl;
}

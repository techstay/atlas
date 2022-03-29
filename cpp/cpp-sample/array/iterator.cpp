#include <array>
#include <iostream>

using namespace std;

int main()
{
    array arr1{1, 2, 3, 4, 5};

    // declaring begin and end iterators
    auto begin{arr1.begin()};
    auto end{arr1.end()};

    for (auto p = begin; p != end; p++)
    {
        cout << *p << " ";
    }
    cout << endl;
}

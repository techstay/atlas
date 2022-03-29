#include <iostream>

using namespace std;

// the raw array are inherited from c and is deprecated,
// so it should be replaced with the vector or the  array in modern c++
int main()
{
    // raw arrays
    double scores[]{1, 2, 3, 4, 5.0};
    int indexes[3]{1, 2, 3};

    // c-style strings
    char str[]{"abcd"};

    // iterating
    // noting that std::size is not available with function parameter arrays!
    for (int i = 0; i < size(indexes); i++)
    {
        cout << indexes[i] << " ";
    }
    cout << endl;
}

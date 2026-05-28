#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Initialize vector
    vector<int> v1 = {1, 2, 3, 4}; // Initializer list
    vector<int> v2(10, 1);         // Size 10, initial value 1
    vector<int> v3{};              // Empty vector

    // Add data dynamically
    for (int i = 0; i < 10; i++)
    {
        v3.push_back(i);
    }
}

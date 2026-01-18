#include <print>

using namespace std;

// Raw arrays are inherited from C and are deprecated
// They should be replaced with std::vector or std::array in modern C++
int main()
{
    // Raw array initialization
    double scores[]{1, 2, 3, 4, 5.0};
    int indexes[3]{1, 2, 3};

    // C-style string
    char str[]{"abcd"};

    // Iterating through the array
    // Note: std::size is not available with function parameter arrays
    for (int i = 0; i < size(scores); i++)
    {
        print("{} ", scores[i]);
    }
    println();
}

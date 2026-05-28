#include <array>
#include <print>

using namespace std;

// std::array knows its size
template <typename T, size_t size>
void print_array(const array<T, size> &a)
{
    for (const auto &i : a)
    {
        print("{} ", i);
    }
    println();
}

int main()
{
    array<int, 5> arr1{1, 2, 3};

    // Generic parameters can be omitted in C++17
    array arr2{1, 2, 3};

    print_array(arr1);
    print_array(arr2);
}

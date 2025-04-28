#include <array>
#include <print>

using namespace std;

// array knows its length
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

    // you can omit generic parameters in c++17
    array arr2{1, 2, 3};

    print_array(arr1);
    print_array(arr2);
}

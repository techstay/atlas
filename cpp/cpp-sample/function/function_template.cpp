#include <iostream>

using namespace std;

template <typename T>
void print(T a)
{
    cout << "a=" << a << endl;
}

template <typename T, typename U>
auto max(T a, U b)
{
    return (a >= b) ? a : b;
}

// abbreviated function templates, available in c++20
auto min(auto a, auto b)
{
    return (a < b) ? a : b;
}

int main()
{
    print<int>(5);
    print(6.0);
    print("abc");
    print("def"sv);

    cout << max(6, 8) << endl;
    cout << min(6, 8) << endl;
}

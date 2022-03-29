#include <functional>
#include <iostream>

// constexpr functions evaluate at compile-time and runtime
constexpr int add(int a, int b)
{
    return a + b;
}

// consteval functions evaluate at compile-time
consteval int minus(int a, int b)
{
    return a - b;
}

int main()
{
    using std::cout;
    using std::endl;

    // both can be executed in compile-time
    cout << add(3, 5) << endl;
    cout << minus(5, 3) << endl;

    // execution in runtime
    int a = 3;
    int b = 5;
    cout << add(a, b) << endl;

    // execution in compile-time
    constexpr int x = 5;
    constexpr int y = 3;
    cout << minus(x, y) << endl;
}

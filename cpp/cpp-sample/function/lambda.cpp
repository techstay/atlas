#include <algorithm>
#include <functional>
#include <iostream>
#include <ostream>

using namespace std;

// lambda parameters
void foo(const function<void()> &callback)
{
    callback();
}

// auto lambda type, available in c++20
void bar(const auto &callback)
{
    callback();
}

// overloading stream << operator
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    out << "[";
    for (const auto &e : v)
    {
        out << e << " ";
    }
    out << "]";
    return out;
}

int main()
{
    // lambdas
    auto sum = [](int a, int b) -> int {
        return a + b;
    };

    cout << "sum: " << sum(2, 3) << endl;

    // lambda arguments
    foo([]() {
        cout << "foo" << endl;
    });

    bar([]() {
        cout << "bar" << endl;
    });

    // sorting
    auto list{
        vector{5, 4, 6, 2, 3, 1, 8}
    };

    sort(list.begin(), list.end(), [](auto a, auto b) {
        return a < b;
    });
    cout << list << endl;
    sort(list.begin(), list.end(), [](auto a, auto b) {
        return a > b;
    });
    cout << list << endl;
}

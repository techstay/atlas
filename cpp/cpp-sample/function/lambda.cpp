#include <algorithm>
#include <functional>
#include <print>
#include <vector>

using namespace std;

// Lambda with std::function parameter
void foo(const function<void()> &callback)
{
    callback();
}

// Lambda with auto parameter is available in C++20
void bar(const auto &callback)
{
    callback();
}

// Print vector helper function
template <typename T>
void print_vector(const vector<T> &v)
{
    std::print("[");
    for (const auto &e : v)
    {
        std::print("{} ", e);
    }
    std::println("]");
}

int main()
{
    // Lambda expression
    auto sum = [](int a, int b) -> int {
        return a + b;
    };

    std::println("sum: {}", sum(2, 3));

    // Lambda as function argument
    foo([]() {
        std::println("foo");
    });

    bar([]() {
        std::println("bar");
    });

    // Sort with lambda
    auto list{
        vector{5, 4, 6, 2, 3, 1, 8}
    };

    sort(list.begin(), list.end(), [](auto a, auto b) {
        return a < b;
    });
    print_vector(list);
    sort(list.begin(), list.end(), [](auto a, auto b) {
        return a > b;
    });
    print_vector(list);
}

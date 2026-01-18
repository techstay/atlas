#include <algorithm>
#include <functional>
#include <print>
#include <vector>

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

// print vector helper
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
    // lambdas
    auto sum = [](int a, int b) -> int {
        return a + b;
    };

    std::println("sum: {}", sum(2, 3));

    // lambda arguments
    foo([]() {
        std::println("foo");
    });

    bar([]() {
        std::println("bar");
    });

    // sorting
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

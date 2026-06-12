import std;

using namespace std::literals;

template <typename T> void print(const T& a) { std::println("a={}", a); }

template <typename T, typename U> auto max(T a, U b) { return (a >= b) ? a : b; }

// Abbreviated function templates (C++20).
// Under the hood, each 'auto' parameter is a distinct template type parameter.
// Equivalent to: template <typename T, typename U> auto min(T a, U b)
auto min(auto a, auto b) { return (a < b) ? a : b; }

int main()
{
    print<int>(5);
    print(6.0);
    print("abc");
    print("def"sv);

    std::println("{}", max(6, 8));
    std::println("{}", min(6, 8));
}

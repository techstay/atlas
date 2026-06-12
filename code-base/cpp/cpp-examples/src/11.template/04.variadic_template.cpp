import std;

// Traditional C++11 recursive base case for printing
void print_all() { std::println(); }

// Traditional C++11 recursive step to expand parameter pack
template <typename T, typename... Args> void print_all(const T& first, const Args&... rest)
{
    std::print("{} ", first);
    print_all(rest...);
}

// Traditional C++11 recursive base case for sum (single argument)
template <typename T> auto sum(T val) { return val; }

// Traditional C++11 recursive step for sum
template <typename T, typename... Args> auto sum(T first, Args... rest)
{ return first + sum(rest...); }

int main()
{
    print_all("values:", 1, 2.5, "done");

    auto total = sum(1, 2, 3, 4, 5);
    auto mixed = sum(1.5, 2, 3.25);

    std::println("total = {}", total);
    std::println("mixed = {}", mixed);
}

import std;

// Unary left fold: (... + pack) -> (((E1 + E2) + E3) + E4)
template <typename... Args> auto sum(Args... args) { return (... + args); }

// Fold over comma to print elements using std::print
template <typename... Args> void print_line(const Args&... args)
{
    ((std::print("{} ", args)), ...);
    std::println();
}

// Unary left fold: (... - pack) -> ((20 - 5) - 3) = 12
template <typename... Args> auto left_subtract(Args... args) { return (... - args); }

// Unary right fold: (pack - ...) -> (20 - (5 - 3)) = 18
template <typename... Args> auto right_subtract(Args... args) { return (args - ...); }

int main()
{
    print_line("sum:", sum(1, 2, 3, 4));
    std::println("left fold: {}", left_subtract(20, 5, 3));
    std::println("right fold: {}", right_subtract(20, 5, 3));
}

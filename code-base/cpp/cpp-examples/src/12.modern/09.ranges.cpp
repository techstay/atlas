import std;

int main()
{
    auto numbers = std::array<int, 100>{};
    std::ranges::generate(numbers, [n{1}]() mutable { return n++; });

    // Reduce using C++23 std::ranges::fold_left
    auto sum = std::ranges::fold_left(numbers, 0, std::plus<>{});
    std::println("sum is {}", sum);

    auto output = numbers | std::views::filter([](int x) { return x % 2 == 0; }) |
                  std::views::transform([](int x) { return x * x; }) | std::views::take(10);

    for (const auto& i : output) { std::print("{} ", i); }
    std::println();
}

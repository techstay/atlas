#include <algorithm>
#include <numeric>
#include <print>
#include <ranges>

using namespace std;

int main()
{
    auto numbers = array<int, 100>{};
    ranges::generate(numbers, [n{1}]() mutable {
        return n++;
    });

    // Reduce
    auto sum = reduce(numbers.begin(), numbers.end(), 0, plus<>{});
    println("sum is {}", sum);

    auto output = numbers | views::filter([](int x) {
                      return x % 2 == 0;
                  }) |
                  views::transform([](int x) {
                      return x * x;
                  }) |
                  views::take(10);

    for (const auto &i : output)
    {
        print("{} ", i);
    }
    println();
}

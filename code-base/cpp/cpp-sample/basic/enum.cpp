#include <format>
#include <print>
#include <string_view>
#include <utility>

using namespace std;

// Unscoped enum
enum Color
{
    RED,
    BLUE,
    GREEN
};

// Scoped enum
enum class Fruit
{
    APPLE,
    BANANA,
    ORANGE
};

template <>
struct std::formatter<Color> : std::formatter<string_view>
{
    auto format(Color c, auto &ctx) const
    {
        constexpr array<string_view, 3> color_names{"RED", "BLUE", "GREEN"};
        return formatter<string_view>::format(color_names[static_cast<int>(c)], ctx);
    }
};

template <>
struct std::formatter<Fruit> : std::formatter<string_view>
{
    auto format(Fruit f, auto &ctx) const
    {
        constexpr array<string_view, 3> fruit_names{"APPLE", "BANANA", "ORANGE"};
        return formatter<string_view>::format(fruit_names[static_cast<int>(f)], ctx);
    }
};

int main()
{
    auto red{RED};
    auto blue{static_cast<Color>(1)};
    println("{}", red);
    println("{}", blue);

    auto apple{Fruit::APPLE};
    auto orange{static_cast<Fruit>(2)};
    println("{}", apple);
    println("{}", orange);

    // Convert enum to underlying type
    // to_underlying is available in C++23
    println("{}", static_cast<int>(orange));
    println("{}", to_underlying(orange));
}

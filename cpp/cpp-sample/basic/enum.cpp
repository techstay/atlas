#include <iostream>
#include <ostream>
#include <utility>

using namespace std;

// unscoped enums
enum Color
{
    RED,
    BLUE,
    GREEN
};

// scoped enums
enum class Fruit
{
    APPLE,
    BANANA,
    ORANGE
};

ostream &operator<<(ostream &out, const Color &color)
{
    switch (color)
    {
    case RED:
        out << "RED";
        break;
    case BLUE:
        out << "BLUE";
        break;
    case GREEN:
        out << "GREEN";
        break;
    }
    return out;
}

ostream &operator<<(ostream &out, const Fruit &fruit)
{
    // using enum class, available in C++20
    using enum Fruit;

    switch (fruit)
    {
    case APPLE:
        out << "Fruit::APPLE";
        break;
    case BANANA:
        out << "Fruit::BANANA";
        break;
    case ORANGE:
        out << "Fruit::ORANGE";
        break;
    }
    return out;
}

int main()
{
    auto red{RED};
    auto blue{static_cast<Color>(1)};
    cout << red << endl;
    cout << blue << endl;

    auto apple{Fruit::APPLE};
    auto orange{static_cast<Fruit>(2)};
    cout << apple << endl;
    cout << orange << endl;

    // converting enum to underlying
    // to_underlying, available in C++23
    cout << static_cast<int>(orange) << endl;
    cout << to_underlying(orange) << endl;
}

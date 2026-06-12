import std;

// Unscoped enum: enumerator names leak into the enclosing namespace
enum Color
{
    Red,
    Green,
    Blue
};

// Scoped enum: enumerator names must be qualified with the enum name
enum class Fruit
{
    Apple,
    Banana,
    Orange
};

// Scoped enum with an explicit underlying type — common in real code to
// keep the size predictable (e.g. for serialization, packed structs, or
// FFI).  Here every enumerator is exactly one byte.
enum class Status : std::uint8_t
{
    Ok       = 0,
    Warning  = 1,
    Error    = 2,
    Critical = 0xFF,
};
static_assert(sizeof(Status) == 1);

const char* fruit_name(Fruit f)
{
    switch (f)
    {
    case Fruit::Apple:
        return "Apple";
    case Fruit::Banana:
        return "Banana";
    case Fruit::Orange:
        return "Orange";
    }
    return "?";
}

int main()
{
    // Unscoped enum: Red is visible without qualification
    auto red{Red};
    auto green{static_cast<Color>(1)}; // 1 corresponds to Green
    std::println("Color[0] = {}, Color[1] = {}", static_cast<int>(red), static_cast<int>(green));

    // C++20: `using enum` brings enumerators into the current scope
    {
        using enum Color;
        auto blue{Blue}; // unqualified
        std::println("Color[2] = {}", static_cast<int>(blue));
    }

    // Scoped enum: must be qualified
    auto apple{Fruit::Apple};
    auto orange{static_cast<Fruit>(2)};
    std::println("Fruit[0] = {}, Fruit[2] = {}", fruit_name(apple), fruit_name(orange));

    // Convert an enumerator to its underlying integer type
    std::println("static_cast<int>: {}", static_cast<int>(orange));
    std::println("to_underlying:   {}", std::to_underlying(orange));

    // Enum with explicit underlying type round-trips through 1 byte.
    Status s = Status::Critical;
    std::println("Status::Critical = 0x{:02X} ({} byte)", std::to_underlying(s), sizeof(s));
}

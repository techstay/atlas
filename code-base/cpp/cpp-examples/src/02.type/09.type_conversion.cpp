import std;

enum class Color
{
    Red,
    Green,
    Blue
};

int main()
{
    int    i = 1'000;
    double d{};

    // Implicit conversion: int -> double (safe, widening)
    d = i;
    std::println("implicit int -> double: {}", d);

    // Explicit conversion using static_cast
    d = static_cast<double>(i);
    std::println("static_cast<double>: {}", d);

    // Pointer round-trip: int* -> void* is implicit, void* -> int* needs static_cast
    int   value = 42;
    void* vp    = &value;
    int*  ip    = static_cast<int*>(vp);
    std::println("void* round-trip: {}", *ip);

    // Enum <-> integer
    Color c   = Color::Green;
    int   idx = static_cast<int>(c);
    Color c2  = static_cast<Color>(2); // Blue
    std::println("Color::Green = {}, Color(2) = {}", idx, static_cast<int>(c2));
}

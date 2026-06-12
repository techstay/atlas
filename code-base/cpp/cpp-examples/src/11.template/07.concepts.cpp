import std;

// Define a concept: a type that supports multiplication (a * b)
template <typename T>
concept Multipliable = requires(T a, T b) {
    { a * b } -> std::convertible_to<T>;
};

// Define a concept combining standard library concepts
template <typename T>
concept Number = std::integral<T> || std::floating_point<T>;

// Using a concept in a requires clause
template <typename T>
    requires Number<T>
T square(T x)
{ return x * x; }

// Using a concept as a type constraint (shorthand syntax)
template <Number T> T cube(T x) { return x * x * x; }

// Abbreviated function template with a concept (C++20)
auto double_it(Number auto x) { return x * 2; }

// Custom concept with multiple requirements
template <typename T>
concept Printable = requires(T x) {
    { std::print("{}", x) }; // must be formattable
};

void print_value(Printable auto const& x) { std::println("value: {}", x); }

// Overloads constrained by different concepts
void describe(std::integral auto x) { std::println("integral: {}", x); }
void describe(std::floating_point auto x) { std::println("floating-point: {:.2f}", x); }

int main()
{
    // Standard library concepts
    std::println("=== Standard Concepts ===");
    std::println("square(5)   = {}", square(5));
    std::println("cube(3)     = {}", cube(3));
    std::println("double(2.5) = {}", double_it(2.5));

    // Custom concept
    std::println("\n=== Custom Multipliable Concept ===");
    auto product = [](Multipliable auto a, Multipliable auto b) { return a * b; };
    std::println("product(3, 4)   = {}", product(3, 4));
    std::println("product(2.5, 3.0) = {}", product(2.5, 3.0));

    // Printable concept
    std::println("\n=== Printable Concept ===");
    print_value(42);
    print_value(3.14);

    // Overload resolution with concepts
    std::println("\n=== Concept-based Overloading ===");
    describe(42);
    describe(3.14);

    // Concepts provide better error messages than SFINAE
    // Uncomment to see a clear concept violation error:
    // square("hello"); // error: "hello" does not satisfy Number
}
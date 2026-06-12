import std;

int main()
{
    // Basic arithmetic operators
    int a = 10, b = 3;
    std::println("a = {}, b = {}", a, b);
    std::println("a + b = {}", a + b); // addition
    std::println("a - b = {}", a - b); // subtraction
    std::println("a * b = {}", a * b); // multiplication
    std::println("a / b = {}", a / b); // integer division (truncates)
    std::println("a % b = {}", a % b); // modulo (remainder)

    // Unary operators
    int c = 5;
    std::println("-c = {}", -c); // negation
    std::println("+c = {}", +c); // unary plus (no-op)

    // Floating-point division (no truncation)
    double x = 10.0, y = 3.0;
    std::println("x / y = {}", x / y);
}

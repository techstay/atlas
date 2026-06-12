import std;

int main()
{
    bool foo = true;
    bool bar = false;

    // C++23 std::println outputs bool as true/false strings by default
    std::println("Default string format: foo={}, bar={}", foo, bar);

    // Use {:d} format specifier to output numeric 1/0 representation
    std::println("Numeric format: foo={:d}, bar={:d}", foo, bar);

    // Boolean operators
    std::println("foo && bar = {}", foo && bar); // logical AND
    std::println("foo || bar = {}", foo || bar); // logical OR
    std::println("!foo       = {}", !foo);       // logical NOT

    // Short-circuit evaluation: the right operand is only evaluated if needed
    int  count  = 0;
    bool result = false && (++count, true); // ++count never executed
    std::println("short-circuit: count={}, result={}", count, result);

    // Implicit conversion: non-zero → true, zero → false
    bool from_int_42 = 42;
    bool from_int_0  = 0;
    std::println("42 → {}, 0 → {}", from_int_42, from_int_0);

    // bool is an integral type — sizeof(bool) is implementation-defined (usually 1)
    std::println("sizeof(bool) = {}", sizeof(bool));
}

import std;

int main()
{
    // --- `auto`: deduce the type from the initializer ---
    auto number     = 100;     // int
    auto number_ptr = &number; // int *
    static_assert(std::is_same_v<decltype(number), int>);
    static_assert(std::is_same_v<decltype(number_ptr), int*>);

    // --- `auto` drops top-level `const` and reference ---
    int            x    = 0;
    const int&     cref = x;
    auto           a    = cref;   // int (both `const` and `&` are stripped!)
    auto&          b    = cref;   // const int& — `auto&` keeps both
    decltype(auto) c    = (cref); // const int& — keeps the exact declared type
    static_assert(std::is_same_v<decltype(a), int>);
    static_assert(std::is_same_v<decltype(b), const int&>);
    static_assert(std::is_same_v<decltype(c), const int&>);

    // --- `decltype`: query the type of an expression at compile time ---
    static_assert(std::is_same_v<decltype(5 + 5), int>);
    static_assert(std::is_same_v<decltype(5 + 5.0), double>);
    // A parenthesized lvalue expression yields a reference type
    static_assert(std::is_same_v<decltype((x)), int&>);

    std::println("number={}, *number_ptr={}", number, *number_ptr);
}

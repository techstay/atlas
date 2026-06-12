import std;

int main()
{
    int i{0};

    // Post-increment: returns original value, then increments
    std::println("i++ = {}", i++); // prints 0, i becomes 1
    // Pre-increment: increments first, then returns new value
    std::println("++i = {}", ++i); // i becomes 2, prints 2

    // Pre-decrement: decrements first, then returns new value
    std::println("--i = {}", --i); // i becomes 1, prints 1
    // Post-decrement: returns original value, then decrements
    std::println("i-- = {}", i--); // prints 1, i becomes 0
}

import std;

int main()
{
    // Basic for loop: init; condition; increment
    for (auto i = 0; i <= 5; i++) { std::print("{} ", i); }
    std::println();

    // Range-based for over a braced initializer list
    for (auto x : {10, 20, 30, 40, 50}) { std::print("{} ", x); }
    std::println();

    // Range-based for over a container; use `const auto&` to avoid copies
    std::vector primes{2, 3, 5, 7, 11};
    for (const auto& p : primes) { std::print("{} ", p); }
    std::println();

    // Infinite loop with break
    auto i = 0;
    for (;;)
    {
        if (i == 5) { break; }
        i++;
    }
    std::println("Infinite loop ends at i = {}.", i);
}

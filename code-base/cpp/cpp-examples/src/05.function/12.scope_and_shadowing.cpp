import std;

// Block and loop shadowing within nested scopes.
// See also: 01.scope.cpp for global vs local scope and :: qualification.

// Block-level shadowing: inner declarations hide outer names within their scope
int main()
{
    auto x = 10;
    std::println("outer x = {}", x);

    {
        auto x = 20;
        std::println("block x = {}", x);
    }

    if (true)
    {
        auto x = 30;
        std::println("if-block x = {}", x);
    }

    for (auto i = 0; i < 1; ++i)
    {
        auto x = 40;
        std::println("for-block x = {}", x);
    }

    std::println("outer x unchanged = {}", x);

    // Loop variable shadowing is a common source of bugs
    auto n = 1;
    std::println("outer n = {}", n);
    for (auto n = 0; n < 3; ++n) { std::print("{} ", n); }
    std::println();
    std::println("outer n unchanged = {}", n);
}

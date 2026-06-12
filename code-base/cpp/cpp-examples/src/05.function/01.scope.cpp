import std;

// Global vs local scope and :: qualification.
// See also: 12.scope_and_shadowing.cpp for block and loop shadowing.

// Global variable with program-wide lifetime
int i{10'000};

int main()
{
    std::println("global variable: {}", i);

    // Local variable in main() shadows the global i within this scope
    int i{1};
    std::println("local variable: {}", i);

    // :: qualifies the global namespace, bypassing local shadowing
    std::println("global via ::i: {}", ::i);
}

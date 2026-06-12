import std;

int main()
{
    // Copy initialization
    int a = 5;

    // Direct initialization
    int b(10);

    // List (brace) initialization — the preferred form
    int c{2};

    // Value initialization with `{}` — zero-initializes built-in types
    int d{};

    std::println("a={}, b={}, c={}, d={}", a, b, c, d);
}

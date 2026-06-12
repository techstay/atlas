import std;

int main()
{
    // Integer family with different widths.  Brace initialization (`{}`)
    // catches narrowing conversions at compile time — see the commented
    // line below.
    short     s{600};
    int       i{1'000};
    long      l{1'000L};
    long long ll{1'000LL};

    // short bad{70'000}; // error: narrowing conversion (70'000 > SHRT_MAX on most platforms)

    // Signed and unsigned variants
    signed int   si{-1'000};
    unsigned int ui{1'000U};

    std::println("short={} int={} long={} long long={}", s, i, l, ll);
    std::println("signed={} unsigned={}", si, ui);

    // Platform-specific limits
    std::println("INT_MAX: {}", std::numeric_limits<int>::max());
    std::println("INT_MIN: {}", std::numeric_limits<int>::min());
}

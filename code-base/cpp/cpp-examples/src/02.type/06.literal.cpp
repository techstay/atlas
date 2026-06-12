import std;

int main()
{
    // Integer literals with type suffixes and digit separators (C++14)
    unsigned int ui = 1'000U;
    long         l  = 1'000L;
    long long    ll = 1'000LL;

    // Different bases.  Note the C-era octal prefix: a leading `0` (NOT
    // `0o`) means octal — `0123` is decimal 83, not 123.  This is a
    // notorious source of bugs; many style guides ban octal literals
    // outside of file-permission constants.
    auto octal  = 01234567;    // octal
    auto hex    = 0xcafe;      // hexadecimal
    auto binary = 0b1111'1110; // binary, since C++14

    // Floating-point literals and scientific notation
    float       f     = 10.0F;
    long double ld    = 200.0L;
    double      pi100 = 3.1415E2;

    std::println("ui={} l={} ll={}", ui, l, ll);
    std::println("octal={:#o} hex={:#x} binary={:#b}", octal, hex, binary);
    std::println("octal (decimal)={} hex (decimal)={} binary (decimal)={}", octal, hex, binary);
    std::println("float={} long double={} pi100={}", f, ld, pi100);

    // ---- User-defined literals (UDL) from the standard library ----
    // Bring the namespaces into scope to use the suffixes.
    using namespace std::chrono_literals;
    using namespace std::string_literals;
    using namespace std::string_view_literals;

    auto timeout  = 250ms;     // std::chrono::milliseconds{250}
    auto half_day = 12h;       // std::chrono::hours{12}
    auto greet    = "hello"s;  // std::string{"hello"}
    auto view     = "world"sv; // std::string_view{"world"}
    std::println("timeout={}, half_day={}, greet={:?}, view={:?}", timeout, half_day, greet, view);
}

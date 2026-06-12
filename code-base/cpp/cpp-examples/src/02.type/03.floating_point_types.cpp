import std;

int main()
{
    // Floating-point family with increasing precision
    float       f  = 3.5F;
    double      d  = 3.5;
    long double ld = 3.1415L;

    std::println("float={} double={} long double={}", f, d, ld);

    // Platform-specific limits
    std::println("DBL_MAX:     {}", std::numeric_limits<double>::max());
    std::println("DBL_MIN:     {}", std::numeric_limits<double>::min());
    std::println("DBL_EPSILON: {}", std::numeric_limits<double>::epsilon());
}

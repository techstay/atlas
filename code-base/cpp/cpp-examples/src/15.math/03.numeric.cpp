import std;

int main()
{
    using namespace std;

    // Integer GCD / LCM (C++17)
    println("gcd(12, 18)  = {}", gcd(12, 18));
    println("lcm( 4,  6)  = {}", lcm(4, 6));

    // Midpoint: overflow-safe average
    int a = numeric_limits<int>::max();
    println("midpoint(INT_MAX, INT_MAX-1) = {}", midpoint(a, a - 1));

    // Sign / compare helpers (integer only)
    println("cmp_equal(1, 1)         = {}", cmp_equal(1, 1));
    println("cmp_not_equal(1, 2)     = {}", cmp_not_equal(1, 2));
    println("cmp_less(-1, 0u)        = {}", cmp_less(-1, 0u));
    println("cmp_less_equal(2, 2)    = {}", cmp_less_equal(2, 2));
    println("cmp_greater(-1, 0u)     = {}", cmp_greater(-1, 0u));
    println("cmp_greater_equal(3, 2) = {}", cmp_greater_equal(3, 2));

    // Type range check
    println("in_range<unsigned>(-1)  = {}", in_range<unsigned>(-1));
    println("in_range<int>(100)      = {}", in_range<int>(100));
}
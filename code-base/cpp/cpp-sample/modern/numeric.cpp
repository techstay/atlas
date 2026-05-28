#include <numeric>
#include <print>

using namespace std;

int main(int argc, const char **argv)
{
    auto a = 6;
    auto b = 4;

    println("gcd: {}", gcd(a, b));
    println("lcm: {}", lcm(a, b));
}

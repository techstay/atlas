#include <print>

using namespace std;

namespace constant
{
// Inline global constants are available in C++17
inline constexpr double PI = 3.14159;
} // namespace constant

int main()
{
    std::println("{}", constant::PI);
}

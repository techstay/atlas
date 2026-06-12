import std;

namespace physics
{
// inline constexpr (C++17): safe to define in headers included by multiple TUs.
// Without 'inline', each TU would get its own definition → ODR violation.
// With 'inline', the linker merges them into a single instance.
inline constexpr double G            = 6.67430e-11; // gravitational constant
inline constexpr double c            = 299'792'458; // speed of light (m/s)
inline constexpr double pi           = std::numbers::pi;
inline constexpr double e            = std::numbers::e;
inline constexpr double golden_ratio = std::numbers::phi;
} // namespace physics

int main()
{
    using namespace physics;

    std::println("=== Mathematical constants ===");
    std::println("pi           = {:.10f}", pi);
    std::println("e            = {:.10f}", e);
    std::println("golden ratio = {:.10f}", golden_ratio);

    std::println("\n=== Physical constants ===");
    std::println("G  = {}", G);
    std::println("c  = {} m/s", c);

    // Practical use: energy-mass equivalence E = mc²
    double mass   = 1.0; // kg
    double energy = mass * c * c;
    std::println("\nE = mc² with m={} kg → E = {:.2e} J", mass, energy);

    // Compare with std::numbers directly
    std::println("\nstd::numbers::pi  = {}", std::numbers::pi);
    std::println("physics::pi       = {}", physics::pi);
    std::println("Same value: {}", std::numbers::pi == physics::pi);
}

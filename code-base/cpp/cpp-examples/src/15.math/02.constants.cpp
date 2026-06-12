import std;

int main()
{
    using namespace std;

    // C++20 <numbers>: typed math constants
    println("pi         = {}", numbers::pi);
    println("e          = {}", numbers::e);
    println("sqrt2      = {}", numbers::sqrt2);
    println("ln2        = {}", numbers::ln2);
    println("log2e      = {}", numbers::log2e);
    println("log10e     = {}", numbers::log10e);
    println("phi        = {}", numbers::phi);
    println("inv_pi     = {}", numbers::inv_pi);     // 1/π
    println("inv_sqrtpi = {}", numbers::inv_sqrtpi); // 1/√π
    println("egamma     = {}", numbers::egamma);     // Euler-Mascheroni constant

    // Template usage for different precision types
    println("\nTemplate-based constants for different precisions:");
    println("pi<float>       = {}", numbers::pi_v<float>);
    println("pi<double>      = {}", numbers::pi_v<double>);
    println("pi<long double> = {}", numbers::pi_v<long double>);

    // Use in a calculation
    double r = 5.0;
    println("\ncircle area={}  circumference={}", numbers::pi * r * r, 2 * numbers::pi * r);
}
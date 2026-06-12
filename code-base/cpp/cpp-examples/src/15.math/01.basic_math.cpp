import std;

int main()
{
    using namespace std;

    // Absolute value
    println("abs(-5)={}  abs(-3.14)={}", abs(-5), abs(-3.14));

    // Power and roots
    println("pow(2,10)={}  sqrt(144)={}  cbrt(27)={}", pow(2, 10), sqrt(144), cbrt(27));

    // Rounding
    println("ceil(2.3)={}  floor(2.7)={}  round(2.5)={}  trunc(-2.7)={}", ceil(2.3), floor(2.7),
            round(2.5), trunc(-2.7));

    // Trigonometry (radians)
    println("sin(pi/2)={}  cos(0)={}  tan(pi/4)={}", sin(numbers::pi / 2), cos(0.0),
            tan(numbers::pi / 4));

    // Hyperbolic
    println("sinh(1)={}  cosh(0)={}  tanh(1)={}", sinh(1.0), cosh(0.0), tanh(1.0));

    // Logarithms
    println("ln(e)={}  log10(1000)={}  log2(16)={}", log(numbers::e), log10(1'000), log2(16));

    // Min / max / clamp
    println("min(3,7)={}  max(3,7)={}  clamp(15, 0, 10)={}", min(3, 7), max(3, 7),
            clamp(15, 0, 10));

    // Floating-point helpers
    double ip;
    double frac = modf(3.14, &ip);
    println("modf(3.14): int={}, frac={}  fmod(5,3)={}  remainder(5,3)={}", ip, frac,
            fmod(5.0, 3.0), remainder(5.0, 3.0));

    // Additional useful functions
    println("hypot(3,4)={}  lerp(0,10,0.3)={}  fma(2,3,4)={}", hypot(3.0, 4.0),
            lerp(0.0, 10.0, 0.3), fma(2.0, 3.0, 4.0));
    println("copysign(1,-3.14)={}  nextafter(1,2)={}  fdim(5,3)={}", copysign(1.0, -3.14),
            nextafter(1.0, 2.0), fdim(5.0, 3.0));
}
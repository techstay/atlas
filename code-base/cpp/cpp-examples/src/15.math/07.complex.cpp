import std;

int main()
{
    using namespace std;
    using namespace std::complex_literals;

    complex<double> z{3, 4};
    println("z={} + {}i  |z|={}  |z|²={}  angle={:.4f}  conj={} + {}i", z.real(), z.imag(), abs(z),
            norm(z), arg(z), conj(z).real(), conj(z).imag());
    println("polar(5, pi/6) = {} + {}i", polar(5.0, numbers::pi / 6).real(),
            polar(5.0, numbers::pi / 6).imag());

    auto w = 1.0 + 2.0i;
    println("w = {} + {}i", w.real(), w.imag());

    complex<double> a{1, 2}, b{3, 4};
    println("a+b = {} + {}i", (a + b).real(), (a + b).imag());
    println("a*b = {} + {}i", (a * b).real(), (a * b).imag());
    println("a/b = {} + {}i", (a / b).real(), (a / b).imag());

    println("proj(z) = {} + {}i", proj(z).real(), proj(z).imag());
    println("proj(w) = {} + {}i", proj(w).real(), proj(w).imag());

    // Euler's identity: e^{i*pi} + 1 ~= 0
    complex<double> euler = exp(complex<double>(0, 1) * numbers::pi) + 1.0;
    println("e^(i*pi) + 1 = {:.6f} + {:.6f}i", euler.real(), euler.imag());
}

import std;

int sum(int a, int b)
{
    std::println("int sum");
    return a + b;
}

double sum(double a, double b)
{
    std::println("double sum");
    return a + b;
}

void print_value(int& value) { std::println("print_value: non-const lvalue ref, value={}", value); }

void print_value(const int& value)
{ std::println("print_value: const lvalue ref, value={}", value); }

int main()
{
    std::println("sum(2, 3) = {}", sum(2, 3));
    std::println("sum(3.0, 4.0) = {}", sum(3.0, 4.0));

    // Integer literal promotes to double, matching the double overload
    std::println("sum(static_cast<double>(3), 100.0) = {}", sum(static_cast<double>(3), 100.0));

    int x{42};
    print_value(x);

    const int y{99};
    print_value(y);

    // Ambiguous overload — do not enable both:
    // void g(int);
    // void g(long);
    // g(0); // error: ambiguous call
}

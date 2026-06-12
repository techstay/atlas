import std;

using namespace std;

template <typename T> void show(const char* name)
{
    using lim = numeric_limits<T>;

    if constexpr (is_integral_v<T>)
    {
        println("{:>5}: min={:>22}  max={:>22}  digits={}  signed={}", name, lim::min(), lim::max(),
                lim::digits, lim::is_signed);
    }
    else if constexpr (is_floating_point_v<T>)
    {
        println("{:>5}: lowest={:>22}  min={:>22}  max={:>22}  eps={:>10}  digits={}  "
                "denorm_min={:>10}",
                name, lim::lowest(), lim::min(), lim::max(), lim::epsilon(), lim::digits,
                lim::denorm_min());
    }
}

void show_boolean_traits()
{
    println("\nBoolean traits:");
    println("{:<8} {:<7} {:<8} {:<7} {:<4} {:<3}", "Type", "signed?", "integer?", "iec559?", "inf?",
            "NaN?");
    println("----------------------------------------");

    auto print_traits = [](auto type, const char* name)
    {
        using T   = decltype(type);
        using lim = numeric_limits<T>;
        println("{:<8} {:<7} {:<8} {:<7} {:<4} {:<3}", name, lim::is_signed, lim::is_integer,
                lim::is_iec559, lim::has_infinity, lim::has_quiet_NaN);
    };

    print_traits(char{}, "char");
    print_traits(int{}, "int");
    print_traits(float{}, "float");
    print_traits(double{}, "double");
}

int main()
{
    show<short>("short");
    show<int>("int");
    show<unsigned>("uint");
    show<long long>("llong");
    show<size_t>("size_t");

    println();
    show<float>("float");
    show<double>("double");

    show_boolean_traits();

    // Special float values
    double zero = 0.0;
    println("\nSpecial values:");
    println("inf  = {}", numeric_limits<double>::infinity());
    println("NaN  = {}", numeric_limits<double>::quiet_NaN());
    println("0/0  = {}", zero / zero);
    println("1/0  = {}", 1.0 / zero);
}

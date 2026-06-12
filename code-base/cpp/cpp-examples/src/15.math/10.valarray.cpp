import std;

int main()
{
    // NOTE: std::valarray is a specialized container for numeric computation.
    // It is rarely used in modern C++ — prefer std::vector with <algorithm>,
    // std::span (C++20), or std::mdspan (C++23) for most use cases.
    // valarray remains useful primarily for legacy codebases and specific
    // numeric workloads where its expression-template optimizations matter.

    using namespace std;

    // Helper function to print valarray and its proxy types
    auto print_va = [](const auto& va)
    {
        print("[");
        bool first = true;
        for (const auto& x : va)
        {
            if (!first) { print(", "); }
            print("{}", x);
            first = false;
        }
        print("]");
    };

    valarray<double> a{1, 2, 3, 4, 5};
    valarray<double> b{10, 20, 30, 40, 50};

    // Element-wise arithmetic
    print("a + b   = ");
    print_va(valarray<double>(a + b));
    println();
    print("a * 2   = ");
    print_va(valarray<double>(a * 2.0));
    println();
    print("a ^ 2   = ");
    print_va(valarray<double>(pow(a, 2.0)));
    println();
    print("sin(a)  = ");
    print_va(valarray<double>(sin(a)));
    println();

    // Reductions
    println("sum(a)  = {}", a.sum());
    println("min(a)  = {}", a.min());
    println("max(a)  = {}", a.max());

    // Apply a function element-wise
    a = a.apply([](double x) { return x * x + 1; });
    print("f(x)=x^2+1 -> ");
    print_va(a);
    println();

    // Dot product of two vectors
    valarray<double> x{1, 2, 3}, y{4, 5, 6};
    println("(x . y) = {}", (x * y).sum());

    // Slice example (strided access)
    valarray<double> v(12);
    iota(begin(v), end(v), 0);
    print("v       = ");
    print_va(v);
    println();
    print("slice   = ");
    print_va(valarray<double>(v[slice(0, 4, 3)]));
    println();

    // Gslice example (multi-dimensional slicing)
    valarray<size_t> lengths{2, 2};
    valarray<size_t> strides{4, 1};
    print("gslice  = ");
    print_va(valarray<double>(v[gslice(0, lengths, strides)]));
    println();

    // Mask array example (boolean mask)
    valarray<bool> mask{false, true, false, true, true,  false,
                        false, true, false, true, false, true};
    print("mask    = ");
    print_va(valarray<double>(v[mask]));
    println();
}

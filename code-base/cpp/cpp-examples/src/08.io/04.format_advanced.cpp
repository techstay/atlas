import std;

// Custom formatter for user-defined type
struct Point
{
    double x, y;
};

template <> struct std::formatter<Point> : std::formatter<string_view>
{
    auto format(const Point& p, auto& ctx) const
    { return std::format_to(ctx.out(), "Point({:.1f}, {:.1f})", p.x, p.y); }
};

int main()
{
    // Basic formatting with positional and named arguments
    std::println("{:*^30}", " Format Demo ");
    std::println();

    // Fill, align, and width
    std::println("|{:>10}|", "right");
    std::println("|{:<10}|", "left");
    std::println("|{:^10}|", "center");
    std::println("|{:*^10}|", "star"); // fill with *

    // Numeric formatting
    double pi = 3.14159265;
    std::println("Default:     {}", pi);
    std::println("Precision 2: {:.2f}", pi);
    std::println("Scientific:  {:e}", pi);
    std::println("Hex:         {:#x}", 255);
    std::println("Binary:      {:#b}", 42);

    // Integer padding and sign
    std::println("Sign always: {:+}", 42);
    std::println("Zero-padded: {:08}", 42);
    std::println("Thousands:   {:#}", 1'000'000); // locale-dep

    // Custom type formatting
    Point p{3.5, 7.2};
    std::println("Custom type: {}", p);

    // std::format returns a string
    auto msg = std::format("Hello, {}! Pi ≈ {:.4f}", "World", pi);
    std::println("format(): {}", msg);
}

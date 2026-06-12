import std;

// std::format (C++20) / std::println (C++23): type-safe string formatting.
// Replacement for printf/sprintf with compile-time format string checking.

int main()
{
    // Basic formatting
    std::println("=== Basic Formatting ===");
    std::println("Hello, {}!", "world");
    std::println("{} + {} = {}", 2, 3, 2 + 3);

    // Positional arguments (reuse arguments)
    std::println("\n=== Positional Arguments ===");
    std::println("{1} comes before {0}", "world", "Hello");
    std::println("{0} + {0} = {1}", 5, 10);

    // Integer formatting: base, sign, padding
    std::println("\n=== Integer Formatting ===");
    std::println("decimal:     {:d}", 255);
    std::println("hex:         {:x}", 255);
    std::println("octal:       {:o}", 255);
    std::println("binary:      {:b}", 255);
    std::println("with sign:   {:+}", 42);
    std::println("zero-padded: {:08d}", 42);

    // Floating-point formatting
    std::println("\n=== Floating-Point Formatting ===");
    double pi = std::numbers::pi;
    std::println("default:     {}", pi);
    std::println("precision 2: {:.2f}", pi);
    std::println("scientific:  {:e}", pi);
    std::println("general:     {:g}", pi);

    // Width, alignment, fill
    std::println("\n=== Width, Alignment, Fill ===");
    std::println("right: |{:>10}|", 42);
    std::println("left:  |{:<10}|", 42);
    std::println("center:|{:^10}|", 42);
    std::println("filled: |{:*^10}|", 42);

    // String and bool formatting
    std::println("\n=== String and Bool ===");
    std::println("string: |{:.5}|", "Hello, World!"); // truncate to 5 chars
    std::println("bool:   {}", true);
    std::println("boolalpha: {:s}", true); // "true" (s = string presentation)

    // std::format_to — write to an output iterator
    std::println("\n=== format_to ===");
    std::string buf;
    std::format_to(std::back_inserter(buf), "pi ≈ {:.4f}", pi);
    std::println("formatted into string: {}", buf);

    // std::formatted_size — get size without allocating
    auto sz = std::formatted_size("{} x {} = {}", 6, 7, 42);
    std::println("formatted_size: {} bytes", sz);
}
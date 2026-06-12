import std;

int main()
{
    std::vector<int> v{5, 2, 8, 1, 9, 3, 7};

    // =============================
    // C++20 ranges-based approach (cleaner syntax)
    // =============================
    std::println("=== C++20 Ranges-Based Approach ===\n");

    // std::ranges::sort — cleaner syntax without .begin()/.end()
    std::ranges::sort(v);
    std::println("Ranges sort: ");
    for (int x : v) { std::print("{} ", x); }
    std::println();

    // std::ranges::find — returns iterator directly from container
    auto range_it = std::ranges::find(v, 8);
    if (range_it != v.end())
    {
        std::println("Ranges find: Found 8 at position {}", std::distance(v.begin(), range_it));
    }

    // std::ranges::transform — apply function to each element (ranges version)
    std::vector<int> range_squares(v.size());
    std::ranges::transform(v, range_squares.begin(), [](int x) { return x * x; });
    std::println("Ranges transform (squares): ");
    for (int x : range_squares) { std::print("{} ", x); }
    std::println();

    // std::ranges::count_if — conditional count (ranges version)
    auto range_even_count = std::ranges::count_if(v, [](int x) { return x % 2 == 0; });
    std::println("Ranges count_if (even numbers): {}", range_even_count);

    // std::ranges::partition — separate elements by predicate
    std::vector<int> v_part = {5, 2, 8, 1, 9, 3, 7};
    auto range_partition_it = std::ranges::partition(v_part, [](int x) { return x % 2 == 0; });
    std::println("Ranges partition (evens first): ");
    for (int x : v_part) { std::print("{} ", x); }
    std::println();

    // std::ranges::any_of — more readable without iterator pairs
    bool range_any_big = std::ranges::any_of(v, [](int x) { return x > 7; });
    std::println("Ranges any_of: Any > 7: {}", range_any_big);

    // =============================
    // C++20 views pipeline examples
    // =============================
    std::println("\n=== C++20 Views Pipeline ===\n");

    // Filter even numbers and print them directly using views
    std::println("Even numbers via views::filter: ");
    for (int x : std::views::iota(1, 11) | std::views::filter([](int x) { return x % 2 == 0; }))
    {
        std::print("{} ", x);
    }
    std::println();

    // Combine filter + transform: filter evens then square them
    std::println("Even squares via filter + transform pipeline: ");
    for (int x : std::views::iota(1, 11) | std::views::filter([](int x) { return x % 2 == 0; }) |
                     std::views::transform([](int x) { return x * x; }))
    {
        std::print("{} ", x);
    }
    std::println();

    // =============================
    // C++23 ranges::to
    // =============================
    std::println("\n=== C++23 Ranges Features ===\n");

    auto even_squares_vec =
        std::views::iota(1, 11) | std::views::filter([](int x) { return x % 2 == 0; }) |
        std::views::transform([](int x) { return x * x; }) | std::ranges::to<std::vector<int>>();

    std::println("Even squares as vector (ranges::to): ");
    for (int x : even_squares_vec) { std::print("{} ", x); }
    std::println();
}

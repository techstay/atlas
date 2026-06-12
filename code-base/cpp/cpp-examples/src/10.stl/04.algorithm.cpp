import std;

int main()
{
    std::vector<int> v{5, 2, 8, 1, 9, 3, 7};

    // =============================
    // Traditional iterator-pair approach (C++03 and later)
    // =============================
    std::println("=== Traditional Iterator-Pair Approach ===\n");

    // std::sort — ascending by default
    std::sort(v.begin(), v.end());
    std::println("Sorted: ");
    for (int x : v) { std::print("{} ", x); }
    std::println();

    // std::find — linear search
    auto it = std::find(v.begin(), v.end(), 8);
    if (it != v.end()) { std::println("Found 8 at position {}", std::distance(v.begin(), it)); }

    // std::transform — apply function to each element
    std::vector<int> squares(v.size());
    std::transform(v.begin(), v.end(), squares.begin(), [](int x) { return x * x; });
    std::println("Squares: ");
    for (int x : squares) { std::print("{} ", x); }
    std::println();

    // std::accumulate — sum to single value
    int sum = std::accumulate(v.begin(), v.end(), 0);
    std::println("Sum: {}", sum);

    // std::count_if — conditional count
    auto even_count = std::count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    std::println("Even numbers: {}", even_count);

    // std::partition — separate elements by predicate (evens first, odds later)
    auto partition_it = std::partition(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    std::println("Partitioned (evens first): ");
    for (int x : v) { std::print("{} ", x); }
    std::println();

    // std::any_of / std::all_of / std::none_of
    bool all_positive = std::all_of(v.begin(), v.end(), [](int x) { return x > 0; });
    bool any_big      = std::any_of(v.begin(), v.end(), [](int x) { return x > 7; });
    std::println("All > 0: {}, Any > 7: {}", all_positive, any_big);

    // std::reverse
    std::reverse(v.begin(), v.end());
    std::println("Reversed: ");
    for (int x : v) { std::print("{} ", x); }
    std::println();
}

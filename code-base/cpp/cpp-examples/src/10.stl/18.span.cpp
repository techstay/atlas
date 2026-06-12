import std;

// std::span (C++20): a non-owning view over a contiguous sequence.
// Like string_view but for any contiguous range (vector, array, C array, etc.)

void print_span(std::span<const int> s)
{
    std::print("[");
    for (std::size_t i = 0; i < s.size(); ++i) { std::print("{}{}", (i ? ", " : ""), s[i]); }
    std::println("] (size={})", s.size());
}

int main()
{
    // span from different container types — all work with the same function
    std::println("=== Span from Different Sources ===");

    int                         c_arr[] = {1, 2, 3, 4, 5};
    std::array<std::int32_t, 4> arr     = {10, 20, 30, 40};
    std::vector<int>            vec     = {100, 200, 300};

    print_span(c_arr); // from C array
    print_span(arr);   // from std::array
    print_span(vec);   // from std::vector

    // Dynamic extent (default) vs fixed extent
    std::println("\n=== Dynamic vs Fixed Extent ===");
    std::span<int>    dynamic_span = vec;   // extent = dynamic_extent
    std::span<int, 5> fixed_span   = c_arr; // extent = 5 (compile-time size)

    std::println("dynamic extent: {}", dynamic_span.size());
    std::println("fixed extent:   {}", fixed_span.size());

    // Subspan — create a view of a sub-range (no copy)
    std::println("\n=== Subspan ===");
    std::span<const int> full = c_arr;
    auto                 mid  = full.subspan(1, 3); // elements 1, 2, 3
    print_span(mid);

    // first(n) / last(n) — convenient sub-view helpers
    std::println("\n=== first / last ===");
    print_span(full.first(3)); // first 3 elements
    print_span(full.last(2));  // last 2 elements

    // span is cheap to copy — just a pointer + size
    std::println("\n=== Span is Cheap ===");
    std::println("sizeof(span<int>) = {}", sizeof(std::span<int>));

    // Modifying through span
    std::println("\n=== Mutation Through Span ===");
    std::span<int> mut_span = vec;
    mut_span[0]             = 999;
    std::println("vec[0] after span mutation: {}", vec[0]);
}

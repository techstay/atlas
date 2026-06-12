import std;

// Function accepting std::span (works with std::any contiguous container)
void print_span(std::span<const int> data)
{
    for (auto value : data) { std::print("{} ", value); }
    std::println();
}

// Span with subspan
void print_first_three(std::span<const int> data)
{
    // Safe guard: data.first(N) requires data.size() >= N, otherwise it is UB.
    auto sub = data.first(std::min(data.size(), std::size_t{3}));
    for (auto value : sub) { std::print("{} ", value); }
    std::println();
}

// Span with dynamic extent
template <std::size_t N> void print_fixed(std::span<const int, N> data)
{
    std::println("Fixed std::span of size {}: ", N);
    for (auto value : data) { std::print("{} ", value); }
    std::println();
}

int main()
{
    // Works with std::vector
    std::vector<int> vec{1, 2, 3, 4, 5};
    print_span(vec);

    // Works with std::array
    std::array<int, 4> arr{10, 20, 30, 40};
    print_span(arr);

    // Works with C-style std::array
    int c_arr[] = {100, 200, 300};
    print_span(c_arr);

    // Subspan operations
    print_first_three(vec);

    // Span of subvector
    auto sub = std::span(vec).subspan(1, 3);
    print_span(sub);

    // Fixed-size span call (static extent)
    print_fixed(std::span<const int, 4>(arr));

    // Data access
    std::span<const int> s{vec};
    std::println("First: {}, Last: {}", s.front(), s.back());
    std::println("Size: {}, Empty: {}", s.size(), s.empty());
}

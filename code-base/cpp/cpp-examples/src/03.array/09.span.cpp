import std;

// std::span<T> is a non-owning view over a contiguous sequence
// Works with raw arrays, std::array, std::vector — same signature
void print(std::span<const int> s)
{
    for (int x : s) { std::print("{} ", x); }
    std::println();
}

int main()
{
    // View over a raw array
    int raw[]{1, 2, 3, 4, 5};
    print(raw);

    // View over a std::array
    std::array arr{10, 20, 30};
    print(arr);

    // View over a std::vector
    std::vector vec{100, 200, 300, 400};
    print(vec);

    // Pointer + length — the C-API bridge
    print({raw + 1, 3}); // {2, 3, 4}

    // Subspan — a window into part of the data
    print(std::span{vec}.subspan(1, 2)); // {200, 300}
}

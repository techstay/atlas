import std;

// std::mdspan (C++23): a multi-dimensional, non-owning view over a contiguous buffer.
// Like std::span but for 2D/3D/ND data. No allocation — just a view.

int main()
{
    // A flat buffer representing a 3×4 matrix
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    // Create a 2D view: 3 rows, 4 columns
    std::mdspan matrix{data.data(), 3, 4};

    std::println("=== 2D Matrix View (3×4) ===");
    std::println("rank (dimensions): {}", matrix.rank());
    std::println("extent(0) rows:    {}", matrix.extent(0));
    std::println("extent(1) cols:    {}", matrix.extent(1));

    // Access elements with multi-dimensional indices
    std::println("\n=== Element Access ===");
    std::println("matrix[0, 0] = {}", matrix[0, 0]);
    std::println("matrix[1, 2] = {}", matrix[1, 2]);
    std::println("matrix[2, 3] = {}", matrix[2, 3]);

    // Iterate over all elements
    std::println("\n=== Row-by-Row Iteration ===");
    for (std::size_t i = 0; i < matrix.extent(0); ++i)
    {
        std::print("row {}: [", i);
        for (std::size_t j = 0; j < matrix.extent(1); ++j)
        {
            std::print("{}{}", (j ? ", " : ""), matrix[i, j]);
        }
        std::println("]");
    }

    // submdspan — create a sub-view (no copy)
    // Note: std::submdspan requires C++26; manually create a sub-mdspan for C++23
    std::println("\n=== sub-view (first 2 rows) ===");
    auto sub = std::mdspan{data.data(), 2, 4};
    for (std::size_t i = 0; i < sub.extent(0); ++i)
    {
        std::print("sub row {}: [", i);
        for (std::size_t j = 0; j < sub.extent(1); ++j)
        {
            std::print("{}{}", (j ? ", " : ""), sub[i, j]);
        }
        std::println("]");
    }

    // mdspan is cheap — just a pointer + extents
    std::println("\n=== mdspan is Cheap ===");
    std::println("sizeof(mdspan<int, dextents<size_t, 2>>) = {}",
                 sizeof(std::mdspan<int, std::dextents<std::size_t, 2>>));

    // Works with std::array too
    std::println("\n=== mdspan from std::array ===");
    std::array<int, 6> arr = {10, 20, 30, 40, 50, 60};
    std::mdspan        arr2d{arr.data(), 2, 3};
    std::println("arr2d[1, 2] = {}", arr2d[1, 2]);
}
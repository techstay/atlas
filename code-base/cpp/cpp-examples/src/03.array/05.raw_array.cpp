import std;

// Raw arrays are inherited from C; prefer std::array / std::vector in modern C++
int main()
{
    // 1D raw array
    double scores[]{1, 2, 3, 4, 5.0};
    for (auto x : scores) { std::print("{} ", x); }
    std::println();

    // 2D raw array — 3 rows of 4 ints, contiguous in memory
    int grid[3][4]{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };
    for (const auto& row : grid)
    {
        for (int x : row) { std::print("{:3} ", x); }
        std::println();
    }
    std::println("grid[1][2] = {}", grid[1][2]);
}

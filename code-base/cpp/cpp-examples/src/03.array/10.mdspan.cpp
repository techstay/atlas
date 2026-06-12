import std;

int main()
{
    // Flat buffer, viewed as a 2 x 3 matrix
    std::vector<int>                                buf(6);
    std::mdspan<int, std::dextents<std::size_t, 2>> m(buf.data(), 2, 3);

    // Write via multi-argument operator[]
    for (std::size_t r = 0; r < m.extent(0); ++r)
    {
        for (std::size_t c = 0; c < m.extent(1); ++c) { m[r, c] = static_cast<int>(r * 10 + c); }
    }

    // Read back
    for (std::size_t r = 0; r < m.extent(0); ++r)
    {
        for (std::size_t c = 0; c < m.extent(1); ++c) { std::print("{:3} ", m[r, c]); }
        std::println();
    }

    std::println("rank = {}, extents = {} x {}", m.rank(), m.extent(0), m.extent(1));
}

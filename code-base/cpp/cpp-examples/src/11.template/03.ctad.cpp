import std;

template <typename T, typename U> struct Pair
{
    T first{};
    U second{};
};

int main()
{
    // Aggregate CTAD (Class Template Argument Deduction) in C++20.
    // Deduces Pair<int, int>
    auto pair1 = Pair{3, 4};

    // Deduces Pair<double, const char*>
    auto pair2 = Pair{3.5, "ctad"};

    std::println("pair1: {}, {}", pair1.first, pair1.second);
    std::println("pair2: {}, {}", pair2.first, pair2.second);
}

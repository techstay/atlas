import std;

int main()
{
    std::array a{1, 2, 3, 4, 5};

    // 1. Range-for — the modern default
    for (const auto& x : a) { std::print("{} ", x); }
    std::println();

    // 2. Iterator — what range-for desugars to
    for (auto it = a.begin(); it != a.end(); ++it) { std::print("{} ", *it); }
    std::println();

    // 3. Index — handy when you need the position
    for (std::size_t i = 0; i < a.size(); ++i) { std::print("{} ", a[i]); }
    std::println();
}

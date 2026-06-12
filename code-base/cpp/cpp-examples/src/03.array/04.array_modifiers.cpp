import std;

int main()
{
    // fill — set every element to a value
    std::array<int, 4> a{};
    a.fill(7);
    for (int x : a) { std::print("{} ", x); }
    std::println();

    // swap — O(1) constant-time exchange (no element copies)
    std::array b{1, 2, 3, 4};
    a.swap(b);

    std::print("a: ");
    for (int x : a) { std::print("{} ", x); }
    std::println();

    std::print("b: ");
    for (int x : b) { std::print("{} ", x); }
    std::println();
}

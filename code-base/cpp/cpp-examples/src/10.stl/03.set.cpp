import std;

int main()
{
    // std::set — sorted unique elements
    std::set<int> s{3, 1, 4, 1, 5, 9}; // duplicates automatically deduplicated
    std::println("std::set (sorted, unique):");
    for (int x : s) { std::print("{} ", x); }
    std::println();

    // std::set with custom comparator (descending order)
    std::set<int, std::greater<int>> s_desc{3, 1, 4, 1, 5, 9};
    std::println("\nstd::set (descending order):");
    for (int x : s_desc) { std::print("{} ", x); }
    std::println();

    // std::multiset — sorted elements with duplicates allowed
    std::multiset<int> ms{3, 1, 4, 1, 5, 9, 5};
    std::println("\nstd::multiset (sorted, duplicates allowed):");
    for (int x : ms) { std::print("{} ", x); }
    std::println();
    std::println("Number of 5's: {}", ms.count(5));

    // std::unordered_set — hash-based unique elements (O(1) average)
    std::unordered_set<int> us{3, 1, 4, 1, 5, 9};
    std::println("\nstd::unordered_set (hash-based, unordered):");
    for (int x : us) { std::print("{} ", x); }
    std::println();

    // C++23: std::flat_set (contiguous storage adapter)
    // Trade-off: better cache locality but linear time inserts/erases
}

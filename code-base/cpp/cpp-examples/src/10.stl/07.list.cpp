import std;

int main()
{
    // std::list supports fast insert/remove, bidirectional iteration.
    std::list<int> l{3, 1, 4};
    l.push_front(2);
    l.push_back(5);
    auto it = std::next(l.begin(), 2);
    l.insert(it, 9);
    l.remove(4);

    // Custom comparator for sort
    l.sort(std::greater<int>{});
    std::println("list (descending):");
    for (int x : l) { std::print("{} ", x); }
    std::println();

    // std::list operations: merge, splice, unique
    std::list<int> l2{6, 2, 8};
    l2.sort();   // Sort for merge
    l.sort();    // Sort for merge
    l.merge(l2); // Merges l2 into l (l2 becomes empty)
    std::println("\nlist after merge:");
    for (int x : l) { std::print("{} ", x); }
    std::println();

    l.splice(l.begin(), l, std::prev(l.end())); // Move last to front
    std::println("\nlist after splice:");
    for (int x : l) { std::print("{} ", x); }
    std::println();

    l.push_back(2); // Add duplicate
    l.push_back(2);
    l.unique(); // Remove consecutive duplicates
    std::println("\nlist after unique:");
    for (int x : l) { std::print("{} ", x); }
    std::println();
}

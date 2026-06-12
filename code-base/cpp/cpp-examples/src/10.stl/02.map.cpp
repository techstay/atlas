import std;

int main()
{
    // std::map — sorted key-value pairs (red-black tree, O(log n))
    std::map<std::string, int> scores{{"Alice", 95}, {"Bob", 87}, {"Charlie", 92}};
    scores["Diana"] = 88;
    std::println("std::map (sorted by key):");
    for (auto& [name, score] : scores) { std::println("  {}: {}", name, score); }

    // std::map bound operations
    std::println("\nstd::map bounds for 'Bob'-'Charlie':");
    auto lower = scores.lower_bound("Bob");     // first element ≥ "Bob"
    auto upper = scores.upper_bound("Charlie"); // first element > "Charlie"
    for (auto it = lower; it != upper; ++it) { std::println("  {}: {}", it->first, it->second); }

    // std::multimap — sorted key-value pairs with duplicate keys
    std::multimap<std::string, int> courses{
        {"math", 90}, {"physics", 85}, {"math", 95}, {"chemistry", 88}};
    std::println("\nstd::multimap (duplicate keys allowed):");
    for (auto& [course, grade] : courses) { std::println("  {}: {}", course, grade); }
    auto math_range = courses.equal_range("math"); // pair of [first, last) for "math"
    std::println("Math grades count: {}", std::distance(math_range.first, math_range.second));

    // std::unordered_map — hash-based key-value pairs (O(1) average)
    std::unordered_map<std::string, std::string> dict{{"hello", "你好"}, {"world", "世界"}};
    dict["cpp"] = "C++";
    std::println("\nstd::unordered_map: hello = {}", dict["hello"]);
    std::println("contains 'rust'? {}", dict.contains("rust"));

    // C++23: std::flat_map (contiguous storage adapter)
    // Trade-off: better cache locality but linear time inserts/erases
}

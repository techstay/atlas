import std;

int main()
{
    // Structured bindings with std::pair
    std::pair<int, std::string> p{1, "hello"};
    auto [id, name] = p;
    std::println("id: {}, name: {}", id, name);

    // Structured bindings with std::tuple
    std::tuple<double, double, double> coord{1.0, 2.0, 3.0};
    auto [x, y, z] = coord;
    std::println("x: {}, y: {}, z: {}", x, y, z);

    // Structured bindings with std::array
    int arr[]      = {10, 20, 30};
    auto [a, b, c] = arr;
    std::println("a: {}, b: {}, c: {}", a, b, c);

    // Structured bindings with std::map
    std::map<std::string, int> scores{{"Alice", 95}, {"Bob", 87}};
    for (auto& [student, score] : scores) { std::println("{}: {}", student, score); }

    // Structured bindings with std::vector of pairs
    std::vector<std::pair<int, bool>> flags{{1, true}, {2, false}, {3, true}};
    for (auto& [value, enabled] : flags) { std::println("value: {}, enabled: {}", value, enabled); }
}

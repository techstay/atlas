#include <boost/bimap.hpp>
#include <print>
#include <string>

int main()
{
    using bm = boost::bimap<std::string, int>;

    bm people;
    people.insert(bm::value_type("Alice", 30));
    people.insert(bm::value_type("Bob", 25));
    people.insert(bm::value_type("Charlie", 35));

    // left view (string -> int)
    std::println("Alice's age: {}", people.left.at("Alice"));

    // right view (int -> string)
    std::println("Age 25: {}", people.right.at(25));

    // iterate left
    std::print("left view: ");
    for (const auto& [name, age] : people.left) { std::print("{}:{} ", name, age); }
    std::println("");

    // iterate right
    std::print("right view: ");
    for (const auto& [age, name] : people.right) { std::print("{}:{} ", age, name); }
    std::println("");

    // size
    std::println("size: {}", people.size());

    return 0;
}

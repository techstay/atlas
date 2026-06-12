// src/boost/04_01_property_tree.cpp - Boost.PropertyTree INI & JSON examples
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <print>
#include <sstream>
#include <string>
#include <utility>

namespace pt = boost::property_tree;

int main()
{
    // build a property tree
    pt::ptree tree;
    tree.put("name", "Alice");
    tree.put("age", 30);
    tree.put("address.city", "Beijing");
    tree.put("address.zip", "100000");

    // add array-like children
    pt::ptree skills;
    for (auto skill : {"C++", "Python", "Rust"})
    {
        pt::ptree child;
        child.put("", skill);
        skills.push_back(std::make_pair("", std::move(child)));
    }
    tree.add_child("skills", skills);

    // serialize to JSON
    std::ostringstream oss;
    pt::write_json(oss, tree, true);
    std::print("JSON output:\n{}", oss.str());

    // read values
    std::println("name: {}", tree.get<std::string>("name"));
    std::println("age: {}", tree.get<int>("age"));
    std::println("city: {}", tree.get<std::string>("address.city"));

    // iterate array
    std::print("skills: ");
    for (const auto& [_, child] : tree.get_child("skills")) { std::print("{} ", child.data()); }
    std::println("");

    // default values
    std::println("missing field: {}", tree.get<std::string>("email", "N/A"));

    // INI format
    pt::ptree ini_tree;
    ini_tree.put("database.host", "localhost");
    ini_tree.put("database.port", 5432);
    ini_tree.put("database.name", "mydb");

    std::ostringstream ini_oss;
    pt::write_ini(ini_oss, ini_tree);
    std::print("\nINI output:\n{}", ini_oss.str());

    // parse INI back
    std::istringstream ini_iss{ini_oss.str()};
    pt::ptree          parsed;
    pt::read_ini(ini_iss, parsed);
    std::println("parsed host: {}", parsed.get<std::string>("database.host"));
}

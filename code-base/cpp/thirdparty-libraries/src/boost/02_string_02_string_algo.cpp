#include <boost/algorithm/string.hpp>
#include <print>
#include <string>
#include <vector>

int main()
{
    std::string s = "  Hello, World!  ";

    // trim
    std::println("trim: [{}]", boost::algorithm::trim_copy(s));
    std::println("trim_copy: [{}]", boost::algorithm::trim_copy(s));

    // case conversion
    std::println("to_upper: {}", boost::algorithm::to_upper_copy(s));
    std::println("to_lower: {}", boost::algorithm::to_lower_copy(s));

    // replace
    std::println("replace: {}", boost::algorithm::replace_all_copy(s, "World", "Boost"));

    // split
    std::vector<std::string> parts;
    boost::algorithm::split(parts, "a,b,,c", boost::is_any_of(","));
    std::print("split: ");
    for (const auto& p : parts) { std::print("[{}] ", p); }
    std::println("");

    // contains / starts_with / ends_with
    std::string text = "hello boost world";
    std::println("contains 'boost': {}", boost::algorithm::contains(text, "boost"));
    std::println("starts_with 'hello': {}", boost::algorithm::starts_with(text, "hello"));
    std::println("ends_with 'world': {}", boost::algorithm::ends_with(text, "world"));

    // join
    std::vector<std::string> words = {"one", "two", "three"};
    std::println("join: {}", boost::algorithm::join(words, " | "));

    return 0;
}

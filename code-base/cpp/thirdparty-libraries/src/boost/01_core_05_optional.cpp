#include <boost/optional/optional.hpp>
#include <print>
#include <string>

boost::optional<std::string> find_name(int id)
{
    if (id == 1) { return std::string("Alice"); }
    return boost::none;
}

int main()
{
    // construction
    boost::optional<int> a(42);
    boost::optional<int> b = boost::none;

    std::println("a has_value: {}, value: {}", a.has_value(), *a);
    std::println("b has_value: {}", b.has_value());

    // value_or
    std::println("b value_or(-1): {}", b.value_or(-1));

    // pointer access
    if (a) { std::println("a via *: {}", *a); }

    // factory function
    auto name = find_name(1);
    std::println("name: {}", name.get_value_or("unknown"));

    auto missing = find_name(99);
    std::println("missing: {}", missing.get_value_or("not found"));

    // comparison
    boost::optional<int> x(10);
    boost::optional<int> y(10);
    std::println("x == y: {}", x == y);

    return 0;
}

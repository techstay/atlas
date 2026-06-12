#include <boost/variant2/variant.hpp>
#include <print>
#include <string>

int main()
{
    using Var = boost::variant2::variant<int, double, std::string>;

    // construction
    Var a(42);
    Var b(3.14);
    Var c("hello");

    // visit
    boost::variant2::visit([](auto&& v) { std::println("value: {}", v); }, a);
    boost::variant2::visit([](auto&& v) { std::println("value: {}", v); }, b);
    boost::variant2::visit([](auto&& v) { std::println("value: {}", v); }, c);

    // get
    std::println("a as int: {}", boost::variant2::get<int>(a));

    // get_if
    if (auto* p = boost::variant2::get_if<double>(&b)) { std::println("b as double: {}", *p); }

    // holds_alternative
    std::println("a holds int: {}", boost::variant2::holds_alternative<int>(a));
    std::println("a holds string: {}", boost::variant2::holds_alternative<std::string>(a));

    // index
    std::println("a index: {}", a.index());

    return 0;
}

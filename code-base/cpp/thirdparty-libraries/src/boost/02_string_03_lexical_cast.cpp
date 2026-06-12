#include <boost/convert.hpp>
#include <boost/convert/stream.hpp>
#include <print>
#include <string>

int main()
{
    namespace cnv = boost::cnv;

    // string to int
    auto i = boost::convert<int>("42", cnv::cstream());
    std::println("42 -> int: {}", i.value_or(0));

    // int to string
    auto s = boost::convert<std::string>(255, cnv::cstream());
    std::println("255 -> string: {}", s.value_or("fail"));

    // string to double
    auto d = boost::convert<double>("3.14", cnv::cstream());
    std::println("3.14 -> double: {:.2f}", d.value_or(0.0));

    // failed conversion
    auto bad = boost::convert<int>("not_a_number", cnv::cstream());
    std::println("bad conversion: {}", bad.has_value());

    // string to bool
    auto b = boost::convert<bool>("true", cnv::cstream());
    std::println("true -> bool: {}", b.value_or(false));

    return 0;
}

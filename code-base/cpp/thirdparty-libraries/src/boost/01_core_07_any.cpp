#include <boost/any.hpp>
#include <print>
#include <string>

int main()
{
    boost::any a = 42;
    boost::any b = std::string("hello");
    boost::any c = 3.14;

    std::println("a type: {}", a.type().name());
    std::println("a value: {}", boost::any_cast<int>(a));
    std::println("b value: {}", boost::any_cast<std::string>(b));
    std::println("c value: {}", boost::any_cast<double>(c));

    // empty check
    boost::any empty;
    std::println("empty empty: {}", empty.empty());

    // type comparison
    std::println("a is int: {}", a.type() == typeid(int));

    // throwing cast
    try
    {
        boost::any_cast<double>(a);
    }
    catch (const boost::bad_any_cast& e)
    {
        std::println("bad cast: {}", e.what());
    }

    // safe cast
    double* p = boost::any_cast<double>(&c);
    std::println("safe cast: {}", p ? std::to_string(*p) : "null");

    // swap
    boost::any x = 100;
    boost::any y = 200;
    x.swap(y);
    std::println("after swap: x={}, y={}", boost::any_cast<int>(x), boost::any_cast<int>(y));

    return 0;
}

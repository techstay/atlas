#include <boost/format.hpp>
#include <iostream>

int main()
{
    // positional args
    std::cout << boost::format("Hello %1%, you are %2% years old") % "Alice" % 30 << "\n";

    // width and alignment
    std::cout << boost::format("%-10s | %10s") % "left" % "right" << "\n";
    std::cout << boost::format("%010d") % 42 << "\n";

    // floating point precision
    std::cout << boost::format("%.3f") % 3.14159265 << "\n";

    // chaining
    auto msg = (boost::format("x=%1%, y=%2%, z=%3%") % 1 % 2.5 % "test").str();
    std::cout << msg << "\n";

    return 0;
}

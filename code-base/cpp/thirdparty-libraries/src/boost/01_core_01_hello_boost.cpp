#include <boost/config.hpp>
#include <boost/version.hpp>
#include <print>

int main()
{
    std::println("=== Boost Hello World ===");
    std::println("Boost version: {}.{}.{}", BOOST_VERSION / 100000, BOOST_VERSION / 100 % 1000,
                 BOOST_VERSION % 100);
    std::println("Compiler: {}", BOOST_COMPILER);
    std::println("Platform: {}", BOOST_PLATFORM);
    std::println("Stdlib: {}", BOOST_STDLIB);
    return 0;
}

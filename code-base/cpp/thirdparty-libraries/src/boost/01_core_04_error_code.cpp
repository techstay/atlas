#include <boost/system/error_code.hpp>
#include <boost/system/system_error.hpp>
#include <print>

int main()
{
    // basic error_code
    boost::system::error_code ec;
    std::println("default error_code: {}", ec.message());

    // custom error
    boost::system::error_code not_found(2, boost::system::system_category());
    std::println("not_found: {}", not_found.message());

    // throwing system_error
    try
    {
        boost::system::error_code file_err(13, boost::system::system_category());
        throw boost::system::system_error(file_err, "open failed");
    }
    catch (const boost::system::system_error& e)
    {
        std::println("caught: {} - {}", e.code().message(), e.what());
    }

    // comparison
    boost::system::error_code a(1, boost::system::system_category());
    boost::system::error_code b(1, boost::system::system_category());
    std::println("a == b: {}", a == b);

    return 0;
}

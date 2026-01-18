#include <cstdlib>
#include <exception>
#include <print>
#include <system_error>

using namespace std;

int main()
{
    try
    {
        throw exception();
    }
    catch (...)
    {
        std::println("exception catch: ");
        // no arguments throw will rethrow the exception
        throw;
    }
}

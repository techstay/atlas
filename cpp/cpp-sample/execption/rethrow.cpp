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
        // Rethrow the current exception
        throw;
    }
}

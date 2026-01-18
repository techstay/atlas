#include <exception>
#include <print>
#include <system_error>

using namespace std;

int main()
{
    try
    {
        throw -1;
    }
    catch (int e)
    {
        std::println("catch exception: {}", e);
    }
    catch (...)
    {
        std::println("catch all");
    }

    try
    {
        throw bad_exception();
    }
    catch (int e)
    {
        std::println("catch exception: {}", e);
    }
    catch (...)
    {
        std::println("catch all");
    }
}

#include <cstdlib>
#include <exception>
#include <iostream>
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
        cout << "exception catch: " << endl;
        // no arguments throw will rethrow the exception
        throw;
    }
}

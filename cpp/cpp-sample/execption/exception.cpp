#include <exception>
#include <iostream>
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
        cout << "catch exception: " << e << endl;
    }
    catch (...)
    {
        cout << "catch all" << endl;
    }

    try
    {
        throw bad_exception();
    }
    catch (int e)
    {
        cout << "catch exception: " << e << endl;
    }
    catch (...)
    {
        cout << "catch all" << endl;
    }
}

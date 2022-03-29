#include <ios>
#include <iostream>

using namespace std;

int main(int argc, const char **argv)
{
    bool foo = true;
    bool bar = false;
    cout << foo << " " << bar << endl;
    // to print true and false, use boolalpha
    cout << boolalpha;
    cout << foo << " " << bar << endl;
    return 0;
}
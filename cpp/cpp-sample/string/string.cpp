#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, const char **argv)
{
    string s{};
    cout << "Input a string:" << endl;

    // ws manipulator skips leading whitespace
    getline(cin >> ws, s);

    cout << "You typed: " << s << endl;
    cout << "The length of strings: " << ssize(s) << endl;
    return 0;
}
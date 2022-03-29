#include <iostream>

using namespace std;

int main()
{
    auto marks = 60;
    switch (marks / 10)
    {
    case 6:
        cout << "passed" << endl;
        break;
    case 7:
    case 8:
        cout << "good" << endl;
        break;
        // multiple situations can be combined together
    case 9:
        // the fallthrough attribute is used to indicate that the following
        // fallthrough is intentional
        [[fallthrough]];
    case 10:
        cout << "excellent" << endl;
        break;
        // default clauses will be executed if others fallthrough
    default:
        cout << "failed" << endl;
    }
}

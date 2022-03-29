#include <iostream>

using namespace std;

int main(int argc, const char **argv)
{
    // if statements
    auto marks = 80;
    if (marks >= 60)
    {
        cout << "passed" << endl;
    }

    marks = 40;
    // if else statements
    if (marks < 60)
    {
        cout << "failed" << endl;
    }
    else
    {
        cout << "passed" << endl;
    }

    // if else if statements
    marks = 100;
    if (marks < 60)
    {
        cout << "failed" << endl;
    }
    else if (marks >= 60 && marks < 100)
    {
        cout << "good" << endl;
    }
    else
    {
        cout << "very good!" << endl;
    }
    return 0;
}
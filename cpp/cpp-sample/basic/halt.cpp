#include <iostream>

using namespace std;

void before_exit()
{
    cout << "before exiting, we should do some cleanup work" << endl;
}

int main()
{
    cout << "do something..." << endl;
    // specifying cleanup functions
    atexit(before_exit);

    exit(0);

    cout << "this will be executed since the program is terminated" << endl;
}

#include <iostream>

#define YES
#define MY_NAME "techstay"

using namespace std;
int main()
{
    // MY_NAME will be replaced with "techstay" by preprocessor
    cout << MY_NAME << endl;

// define directive could also be used for conditional compilation
#ifdef YES
    cout << "You will see this line if YES is defined." << endl;
#endif
}
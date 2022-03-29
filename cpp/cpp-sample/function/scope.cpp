#include <iostream>

using namespace std;

// global variables
int i{10'000};

int main()
{
    cout << "global variable:" << i << endl;

    // shadowing global variables
    int i{1};
    cout << "local variable:" << i << endl;

    // global namespace
    cout << "using global namespace:" << ::i << endl;
}

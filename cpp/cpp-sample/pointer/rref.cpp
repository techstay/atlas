#include <iostream>

using namespace std;

// overloading functions for lref and rref
void print_ref(const int &lref)
{
    cout << "lref: " << lref << endl;
}

void print_ref(int &&rref)
{
    cout << "rref: " << rref << endl;
}

int main()
{
    int x{3};
    int &&y{5};
    print_ref(x);
    print_ref(5);
    // y is lref even if its type is rref
    print_ref(y);
}

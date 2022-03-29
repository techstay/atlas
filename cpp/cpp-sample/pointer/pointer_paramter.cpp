#include <cstddef>
#include <iostream>

using namespace std;

// three overloading functions
void print_ptr(int *ptr)
{
    cout << "ptr: " << ptr << "\tvalue: " << *ptr << endl;
}

void print_ptr(int i)
{
    cout << "integer: " << i << endl;
}

void print_ptr(nullptr_t ptr)
{
    cout << "this is nullptr" << endl;
}

int main()
{
    int a{100};
    // calling the overloading functions
    print_ptr(0);
    print_ptr(nullptr);
    print_ptr(&a);
}

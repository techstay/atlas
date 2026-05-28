#include <iostream>

using namespace std;

int main()
{
    int a{3};
    int b{6};

    // Pointer to const: value cannot be modified through pointer
    const int *ptr_a = &a;
    // *ptr_a = 6;  // Error: cannot modify const value
    ptr_a = &b;     // OK: pointer can be reassigned

    // Const pointer: pointer cannot be reassigned
    int *const ptr_b = &b;
    *ptr_b = 100;   // OK: value can be modified
    // ptr_b = &a;   // Error: cannot reassign const pointer
}

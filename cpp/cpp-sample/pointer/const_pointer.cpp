#include <iostream>

using namespace std;

int main()
{
    int a{3};
    int b{6};

    // the pointer to constants, the value being pointed to can't be changed
    const int *ptr_a = &a;
    // we can't changed the actual value
    // *ptr_a           = 6;
    // but the pointer itself can be reseated
    ptr_a = &b;

    // the const pointer, the pointer itself can't be changed
    int *const ptr_b = &b;
    // we can change the pointing value
    *ptr_b = 100;
    // but the pointer itself is const
    // ptr_b = &a;
}

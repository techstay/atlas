#include <print>
using namespace std;

int main()
{
    // typedef keyword
    typedef int integer;
    integer i = 5;

    typedef int *pointer;
    pointer p1 = &i;

    println("*p1={}", *p1);

    // Type alias declaration
    using charater = char;
    charater c     = 'c';

    // auto keyword
    auto number     = 100;     // number is int
    auto number_ptr = &number; // number_ptr is int*
    auto ca         = 'a';

    // decltype keyword, type deduction
    decltype(5 + 5) n1;     // int
    decltype(5 + 5.0) n2;   // double
    decltype((n2)) n3 = n2; // int&
}

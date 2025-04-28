#include <print>
using namespace std;

int main()
{
    // typedef关键字
    typedef int integer;
    integer i = 5;

    typedef int *pointer;
    pointer p1 = &i;

    println("*p1={}", *p1);

    // 别名声明
    using charater = char;
    charater c     = 'c';

    // auto关键字
    auto number     = 100;     // number是int
    auto number_ptr = &number; // number_ptr是int*
    auto ca         = 'a';

    // decltype关键字，类型推导
    decltype(5 + 5) n1;     // int
    decltype(5 + 5.0) n2;   // double
    decltype((n2)) n3 = n2; // int&
}

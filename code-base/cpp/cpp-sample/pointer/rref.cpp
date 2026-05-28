#include <print>

using namespace std;

// Overloaded functions for lvalue and rvalue references
void print_ref(const int &lref)
{
    std::println("lref: {}", lref);
}

void print_ref(int &&rref)
{
    std::println("rref: {}", rref);
}

int main()
{
    int x{3};
    int &&y{5};    // y is an rvalue reference bound to rvalue 5
    print_ref(x);  // x is lvalue, binds to lvalue reference
    print_ref(5);  // 5 is rvalue, binds to rvalue reference
    print_ref(y);  // y is lvalue (named rvalue reference), binds to lvalue reference
}

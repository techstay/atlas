#include <print>

using namespace std;

// overloading functions for lref and rref
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
    int &&y{5};
    print_ref(x);
    print_ref(5);
    // y is lref even if its type is rref
    print_ref(y);
}

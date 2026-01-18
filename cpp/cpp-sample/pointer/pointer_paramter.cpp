#include <cstddef>
#include <print>

using namespace std;

// three overloading functions
void print_ptr(int *ptr)
{
    std::println("ptr: {}\tvalue: {}", static_cast<const void*>(ptr), *ptr);
}

void print_ptr(int i)
{
    std::println("integer: {}", i);
}

void print_ptr(nullptr_t ptr)
{
    std::println("this is nullptr");
}

int main()
{
    int a{100};
    // calling the overloading functions
    print_ptr(0);
    print_ptr(nullptr);
    print_ptr(&a);
}

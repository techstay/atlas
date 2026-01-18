#include <cstddef>
#include <print>

using namespace std;

// Function overloading demonstration
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
    // Demonstrate overload resolution: 0 matches int, nullptr matches nullptr_t
    print_ptr(0);
    print_ptr(nullptr);
    print_ptr(&a);
}

#include <functional>
#include <print>

using namespace std;

// Accept two parameters and return a pointer to the result
int *foo(int a, int b)
{
    return new int[]{a + b};
}

int main()
{
    // Traditional way to define a function pointer
    int *(*ptr1)(int, int){foo};

    // Modern way to define a function pointer
    using type_foo = int *(*)(int, int);
    type_foo ptr2{foo};

    // Use std::function to define a function pointer
    function<int *(int, int)> ptr3{foo};

    // Type inference
    auto ptr4{&foo};

    std::println("foo1: {}", *ptr1(2, 3));
    std::println("foo2: {}", *ptr2(2, 3));
    std::println("foo3: {}", *ptr3(2, 3));
    std::println("foo4: {}", *ptr4(2, 3));
}

import std;

// See also: 04.pointer/12.function_pointer.cpp (passing function pointers as arguments)

int foo(int a, int b) { return a + b; }

int main()
{
    // Traditional function pointer syntax
    int (*ptr1)(int, int){foo};

    // Type alias for readability
    using FuncPtr = int (*)(int, int);
    FuncPtr ptr2{foo};

    // std::function is a type-erased callable wrapper, not a raw function pointer.
    // It may heap-allocate and adds indirection overhead compared to a function pointer.
    std::function<int(int, int)> callable{foo};

    // auto deduces a function pointer type when initialized with &foo
    auto ptr3{&foo};

    std::println("ptr1: {}", ptr1(2, 3));
    std::println("ptr2: {}", ptr2(2, 3));
    std::println("callable: {}", callable(2, 3));
    std::println("ptr3: {}", ptr3(2, 3));
}

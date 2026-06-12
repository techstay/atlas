import std;

int main()
{
    int i = 5;
    int j = 100;

    // Top-level const: the pointer itself is const
    int* const cp = &i;
    *cp           = 10; // OK: can modify the pointed-to value
    // cp = &j;          // Error: pointer itself is const
    std::println("*cp={}", *cp);

    // Low-level const: the pointed-to value is const
    const int* p = &i;
    p            = &j; // OK: can point to a different object
    // *p = 200;        // Error: cannot modify through const pointer
    std::println("*p={}", *p);

    // `const int *` and `int const *` are exactly the same type.
    // Reading C++ declarations RIGHT-TO-LEFT removes the ambiguity:
    //   `int const *  p2`  -> p2 is a pointer to a const int
    //   `const int *  p`   -> p  is a pointer to a const int  (same)
    //   `int *const   cp`  -> cp is a const pointer to an int
    int const* p2 = p;
    static_assert(std::is_same_v<decltype(p), decltype(p2)>);

    // Both top-level and low-level const
    const int* const ccp = &i;
    std::println("*ccp={}", *ccp);
}

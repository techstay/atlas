import std;

int main()
{
    int a = 3, b = 6;

    // 1. pointer to const: cannot modify value, but can be repointed
    const int* p1 = &a;
    p1            = &b; // OK
    // *p1 = 100;                           // Error: read-only

    // 2. const pointer: cannot be repointed, but can modify value
    int* const p2 = &b;
    *p2           = 100; // OK
    // p2 = &a;                             // Error: const pointer

    // 3. const pointer to const: neither
    const int* const p3 = &a;

    std::println("a={}, b={}", a, b);
}

import std;

int main()
{
    // Demonstrates array-to-pointer decay and whole-array reference.
    int arr[] = {10, 20, 30, 40, 50};

    int* p = arr;                    // array decays to pointer to first element
    std::println("*p   = {}", *p);   // 10
    std::println("p[2] = {}", p[2]); // 30 — pointer supports subscript operator

    int (&ref)[5] = arr; // reference to the whole array (size matters)
    std::println("ref[3] = {}", ref[3]);

    std::println("sizeof(arr)={}, sizeof(p)={}", sizeof(arr), sizeof(p));

    // std::size is type-safe and respects the array type (no decay).
    std::println("std::size(arr)={}", std::size(arr));
}

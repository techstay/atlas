import std;

int main()
{
    int  arr[] = {10, 20, 30, 40, 50};
    int* p     = arr;

    std::println("*(p+0) = {}", *(p + 0)); // 10
    std::println("*(p+1) = {}", *(p + 1)); // 20
    std::println("*(p+3) = {}", *(p + 3)); // 40

    p += 2;                                // advance by 2 elements
    std::println("*p     = {}", *p);       // 30
    std::println("p - arr = {}", p - arr); // 2 (pointer difference in elements)

    // Reverse iteration
    int* it = arr + 4;
    do
    {
        std::print("{} ", *it);
        if (it == arr) { break; }
        --it;
    } while (true);
    std::println();
}

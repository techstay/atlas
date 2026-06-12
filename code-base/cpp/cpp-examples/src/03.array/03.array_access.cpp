import std;

int main()
{
    std::array a{10, 20, 30, 40, 50};

    // operator[] — unchecked, zero-overhead
    std::println("a[0] = {}", a[0]);

    // at() — bounds-checked, throws std::out_of_range on bad index
    std::println("a.at(2) = {}", a.at(2));

    // front / back — convenient ends
    std::println("front = {}, back = {}", a.front(), a.back());

    // data() — raw pointer to the contiguous storage
    int* p = a.data();
    std::println("*p = {}", *p);

    // [] is UB on bad index; at() throws
    try
    {
        (void)a.at(99);
    }
    catch (const std::out_of_range& e)
    {
        std::println("caught: {}", e.what());
    }
}

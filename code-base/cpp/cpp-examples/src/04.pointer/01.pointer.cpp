import std;

int main()
{
    int  a = 10;
    int* p = &a; // p holds the address of a

    std::println("a={}, *p={}", a, *p);

    *p = 20; // modify a through pointer
    std::println("a={}, *p={}", a, *p);

    int* q = nullptr; // null pointer
    std::println("q is {}", q ? "valid" : "null");
}

import std;

int main()
{
    // C-style string: null-terminated char array
    char str[] = "abcd";
    // sizeof includes the null terminator
    std::println("sizeof(str):   {}", sizeof(str)); // 5 (4 chars + '\0')

    // strlen counts characters excluding the null terminator
    std::println("strlen(str):   {}", std::strlen(str)); // 4

    // String literals are const — modifying them is undefined behavior
    const char* p = "hello";
    // p[0] = 'H'; // error: assignment of read-only location

    // Pointer comparison compares addresses, not content
    const char* a = "test";
    const char* b = "test";
    std::println("a == b:         {}", a == b);                 // implementation-defined
    std::println("strcmp:         {}", std::strcmp(a, b) == 0); // reliable
}

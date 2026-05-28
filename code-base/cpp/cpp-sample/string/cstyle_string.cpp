#include <print>

using namespace std;

int main()
{
    // C-style string with null terminator
    char str1[] = "abcd";
    // Actual size is 5 bytes (4 chars + '\0')
    std::println("The length of str1: {}", sizeof(str1));
}

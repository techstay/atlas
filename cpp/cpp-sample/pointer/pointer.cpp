#include <print>

using namespace std;

int main()
{
    int d1 = 5;
    int d2 = 6;

    // Declare two pointers
    int *p1, *p2;

    // Assign addresses to pointers
    p1 = &d1;
    p2 = &d2;

    // Access objects through pointers
    std::println("d1={}, *p1={}", d1, *p1);

    // Modify object via pointer
    *p1 = 100;
    std::println("d1={}, *p1={}", d1, *p1);

    // Reset pointers to null
    p1 = p2 = nullptr;
}
int main()
{
    int i        = 5;
    const int &r = i;
    i            = 10;
    // r            = 10; // r is const and cannot be modified

    int j = 100;
    // Const pointer (top-level const)
    int *const cp = &i;
    // Modify the value through the pointer
    *cp = 10;
    // Cannot modify the pointer itself
    // cp = &j;

    const int *p = &i;
    // Can modify the pointer to point to a different object
    p = &j;
    // Cannot modify the value through the pointer
    // *p = 200;

    // Both top-level and low-level const
    const int *const ccp = &i;

    // Constant expressions
    constexpr int MAX_COUNT = 100;
    constexpr int MIN_COUNT = -MAX_COUNT;
    // i is not const, so the following code cannot compile
    // constexpr int VARIABLE_COUNT = i;
}

import std;

// Pitfall 1: Missing parentheses causes operator precedence bugs
#define ADD(a, b) a + b
#define SAFE_ADD(a, b) ((a) + (b))

// Pitfall 2: Multiple evaluation — arguments with side effects are evaluated more than once
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Pitfall 3: Multi-statement macro without do-while wrapper breaks in if/else
#define BAD_SWAP(a, b)                                                                             \
    int t = (a);                                                                                   \
    (a)   = (b);                                                                                   \
    (b)   = t;
#define GOOD_SWAP(a, b)                                                                            \
    do                                                                                             \
    {                                                                                              \
        int t = (a);                                                                               \
        (a)   = (b);                                                                               \
        (b)   = t;                                                                                 \
    } while (0)

int main()
{
    // Pitfall 1: ADD(3, 5) * 2 expands to 3 + 5 * 2 = 13, not 16
    std::println("ADD(3,5)*2    = {}", ADD(3, 5) * 2);
    std::println("SAFE_ADD(3,5)*2 = {}", SAFE_ADD(3, 5) * 2);

    // Pitfall 2: MAX(x++, y++) increments the winner twice
    int x = 5, y = 3;
    std::println("Before: x={}, y={}", x, y);
    int m = MAX(x, y);
    std::println("MAX(x,y)={}, After: x={}, y={}", m, x, y);
    std::println("(y was incremented twice: once in condition, once in ternary)");

    // Pitfall 3: BAD_SWAP with if/else — macro body grabs only the first statement
    // The else binds to the wrong if after expansion, causing a compile error:
    //   if (a < b) int t = a; a = b; b = t; else ...
    // Uncomment below to see the compile error:
    // int a = 1, b = 2;
    // if (a < b) BAD_SWAP(a, b) else std::println("no swap needed");

    // With do-while wrapper, the macro is a single statement that works correctly
    int a = 1, b = 2;
    if (a < b) { GOOD_SWAP(a, b); }
    else
    {
        std::println("no swap needed");
    }
    std::println("After GOOD_SWAP: a={}, b={}", a, b);
}

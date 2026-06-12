import std;

#define mian main
#define O 0
#define true false

bool tell_me_truth() { return true; }

// # Stringizing operator: converts a macro argument to a string literal
#define TO_STR(x) #x
#define PRINT_VAR(var) std::println(#var " = {}", var)

// ## Token pasting operator: concatenates two tokens into one identifier
#define PASTE(a, b) a##b
#define MAKE_VAR(n) int var_##n = n * 10

int mian()
{
    std::println("{}", tell_me_truth());
    std::println("{}", O);

    // Stringizing
    std::println("{}", TO_STR(hello world));
    int value = 42;
    PRINT_VAR(value);

    // Token pasting
    std::println("PASTE(6, 4) = {}", PASTE(6, 4)); // expands to 64

    MAKE_VAR(3);
    MAKE_VAR(7);
    std::println("var_3 = {}, var_7 = {}", var_3, var_7);

    return O;
}

import std;

int main()
{
    // sizeof is a compile-time unary operator
    std::println("=== sizeof on fundamental types ===");
    std::println("sizeof(bool)        = {}", sizeof(bool));
    std::println("sizeof(char)        = {}", sizeof(char));
    std::println("sizeof(short)       = {}", sizeof(short));
    std::println("sizeof(int)         = {}", sizeof(int));
    std::println("sizeof(long)        = {}", sizeof(long));
    std::println("sizeof(long long)   = {}", sizeof(long long));
    std::println("sizeof(float)       = {}", sizeof(float));
    std::println("sizeof(double)      = {}", sizeof(double));
    std::println("sizeof(long double) = {}", sizeof(long double));
    std::println("sizeof(void*)       = {}", sizeof(void*));

    std::println();
    std::println("=== sizeof on variables ===");
    auto i = 0;
    auto d = 3.14;
    std::println("sizeof(i) = {}", sizeof(i));
    std::println("sizeof(d) = {}", sizeof(d));

    std::println();
    std::println("=== sizeof on expressions (not evaluated) ===");
    // The operand is not evaluated, only its type matters
    std::println("sizeof(i + 1.0)   = {}", sizeof(i + 1.0));
    std::println("sizeof(i + 1LL)   = {}", sizeof(i + 1LL));

    // sizeof(char) is always 1 by definition
    std::println("sizeof(char) is always 1: {}", sizeof(char));
}

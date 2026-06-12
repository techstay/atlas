import std;

int main()
{
    // Comma operator: evaluates left-to-right, the value of the
    // entire expression is the right-hand operand.
    int i = (3, 4);
    std::println("int i = (3, 4);  -> i = {}", i);

    // Often used in for-loops to update multiple variables
    for (int a = 0, b = 10; a < b; a++, b--) { std::println("a = {}, b = {}", a, b); }
}

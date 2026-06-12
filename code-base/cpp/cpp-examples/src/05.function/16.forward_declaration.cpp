import std;

// Forward declaration: tells the compiler a function exists before its definition
int  add(int a, int b);
void greet(std::string_view name);

int main()
{
    std::println("add(3, 4) = {}", add(3, 4));
    greet("world");
}

int add(int a, int b) { return a + b; }

void greet(std::string_view name) { std::println("hello, {}!", name); }

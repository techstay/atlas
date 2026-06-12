import std;

// Default parameters must appear at the end of the parameter list
void print_two(int a, int b = 0) { std::println("print_two: a={}, b={}", a, b); }

void print_three(int a, int b = 0, int c = 1)
{ std::println("print_three: a={}, b={}, c={}", a, b, c); }

// Default arguments belong in the declaration, not repeated in the definition
void log_message(int level, std::string_view msg = "no message");

void log_message(int level, std::string_view msg)
{ std::println("log_message: level={}, msg={}", level, msg); }

// Ambiguous overload with default arguments — do not enable both:
// void f(int);
// void f(int, int = 0);
// f(0); // error: ambiguous call

int main()
{
    print_two(3);
    print_two(3, 4);

    print_three(10);
    print_three(10, 20);
    print_three(10, 20, 30);

    log_message(1);
    log_message(2, "hello");
}

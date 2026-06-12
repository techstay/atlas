import std;

int square(int x) { return x * x; }

void print_result(int value, int (*operation)(int))
{ std::println("result: {}", operation(value)); }

int main()
{
    using Operation = int (*)(int);
    Operation op    = square;

    std::println("direct pointer call: {}", op(4));
    print_result(5, op);
}

import std;

void increment_and_print()
{
    // Initialized exactly once; lifetime spans the entire program
    // Thread-safe initialization since C++11 (magic statics)
    static int count{0};
    std::println("count = {}", ++count);
}

int main()
{
    increment_and_print();
    increment_and_print();
    increment_and_print();
}

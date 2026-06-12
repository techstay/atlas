import std;

void show(int*) { std::println("int*"); }

void show(int) { std::println("int"); }

void show(std::nullptr_t) { std::println("nullptr_t"); }

int main()
{
    int x = 0;

    show(&x);      // int*
    show(42);      // int
    show(nullptr); // nullptr_t — unambiguous null pointer literal

    show(0); // calls show(int) — surprising if you meant the pointer overload
    // show(NULL);  // implementation-defined: may be ambiguous if NULL is defined as 0L
}

import std;

// Static / namespace-scope built-ins are *zero-initialized* before main()
// runs, regardless of how they are declared.  This is one of the few cases
// where leaving an `int` "uninitialized" is actually safe.
int g_zero;

int main()
{
    // 1. Local built-in declared without an initializer: default-init,
    //    which for built-ins means "indeterminate value".  Reading it is
    //    undefined behaviour, so we never print it.
    [[maybe_unused]] int x;
    std::println("{}", x); // <-- would be UB; left uncommented on purpose

    // 2. Value-initialization with `{}` — always zero for built-ins.
    int y{};
    std::println("y = {}", y);

    // 3. Namespace-scope variables are zero-initialized before `main`.
    std::println("g_zero = {}", g_zero);

    // 4. `new int` vs `new int{}` differ exactly the same way:
    //      `new int`   -> default-init, indeterminate value
    //      `new int{}` -> value-init, zeroed
    auto* p1 = new int{}; // safe
    std::println("new int{{}} = {}", *p1);
    delete p1;

    // 5. Common pitfall — std::vector<int> v(N) IS zero-initialized.
    //    Many C++ readers expect `v(10)` to leave 10 indeterminate ints
    //    (because that is what `int a[10];` does), but vector value-
    //    initializes its elements: every element is 0.
    std::vector<int> v(10);
    std::println("vector v(10) = {}", v);
}

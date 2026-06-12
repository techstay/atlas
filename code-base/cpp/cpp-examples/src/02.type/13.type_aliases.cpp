import std;

// --- typedef: C-style type alias (legacy, prefer `using`) ---
typedef unsigned long ULong;
typedef int           Integer;

// --- using: the modern C++ alias syntax (C++11+) ---
using UInt   = unsigned int;
using IntPtr = int*;

// --- function pointer alias ---
int add(int x, int y) { return x + y; }

using AddFn = int (*)(int, int);

// --- template alias: only `using` can express this ---
template <typename T> using Vec = std::vector<T>;

int main()
{
    ULong   a = 100;
    UInt    b = 200;
    Integer c = 5;

    IntPtr p = &c;
    std::println("a={}, b={}, c={}, *p={}", a, b, c, *p);

    AddFn f = add;
    std::println("f(3, 4) = {}", f(3, 4));

    Vec<int> v = {1, 2, 3};
    std::println("v = [{} {} {}]", v[0], v[1], v[2]);

    // Aliases are fully interchangeable with the underlying type — both
    // typedef and `using` create a NAME, not a new type.  Functions that
    // take `int` accept `Integer` without any conversion, and vice versa.
    static_assert(std::is_same_v<UInt, unsigned int>);
    static_assert(std::is_same_v<ULong, unsigned long>);
    static_assert(std::is_same_v<Integer, int>);

    // If you actually want a *distinct* type (so the compiler can stop
    // you from passing a UserId where a ProductId is expected), use
    // `enum class` (with an explicit underlying type) or wrap the value
    // in a small struct.  Plain typedef/using will not give you that
    // safety.
}

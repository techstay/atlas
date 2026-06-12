// `assert` is a preprocessor macro defined in <cassert>, not a function.
// That is why this file uses #include instead of `import std;` — macros
// cannot be exported through C++ modules.
//
// `assert(expr)` evaluates `expr` only in debug builds. When `NDEBUG` is
// defined (typical in release builds), the entire expression is removed,
// so never put code with side effects inside `assert(...)`.
#include <cassert>

int main()
{
    auto i = 5;

    // Holds — execution continues silently.
    assert(i == 5);

    // Fails on purpose: aborts the program with a diagnostic message
    // pointing to this file and line. Anything written after this point
    // would not run in a debug build.
    assert(i % 2 == 0);
}

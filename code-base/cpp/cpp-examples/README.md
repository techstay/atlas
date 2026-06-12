# cpp-examples

A collection of concise, single-file C++ examples organized by topic. Each example demonstrates a specific language feature or standard library facility.

## Project Highlights

- **xmake-based build** — multi-target support; each example is an independent target that can be built and run individually.
- **Shared std module** — standard library modules (`std`, `std.compat`) are compiled once and reused across all targets, avoiding redundant compilation.
- **Quick run workflow** — open any `.cpp` file in VS Code, then run the "run build task" command to compile and run it instantly.
- **Pure modern C++** — all examples use `import std;` (no `#include` for standard headers), showcasing modern module-based development.
- **clang-tidy linting** — static analysis runs on every file to enforce best practices and catch common pitfalls.
- **Cross-platform** — the xmake config auto-detects the platform and switches toolchains accordingly (MSVC on Windows, Clang on Linux), no manual configuration needed.
- **Dev container ready** — a Fedora-based dev container comes pre-installed with GCC, Clang, GDB, LLDB, ccache, and essential VS Code extensions (code-runner, clangd, xmake, LLDB, etc.). Open in VS Code and start coding immediately. Fish shell is the default terminal for a friendlier out-of-the-box experience.
- **Unified code style** — `.clang-format` enforces Allman brace style, 4-space indentation, 100-column limit, and aligned assignments/declarations for consistent formatting.
- **Debug support** — GDB and LLDB are installed in the dev container, with the VS Code LLDB extension pre-configured for breakpoint debugging out of the box.

## Directory Structure

- **[01.basic/](src/01.basic/)** — Basic syntax: variables, control flow, conditionals, loops, assertions, etc.
- **[02.type/](src/02.type/)** — Type system: integer/float/character types, type conversion, literals, `const`, enums, type aliases, type deduction, etc.
- **[03.array/](src/03.array/)** — Arrays & containers: raw arrays, `std::array`, `std::vector`, `std::span`, `std::mdspan`, traversal, access, modifiers, capacity, etc.
- **[04.pointer/](src/04.pointer/)** — Pointers & references: pointer arithmetic, `nullptr`, const pointers, lvalue/rvalue references, smart pointers, `weak_ptr`, cyclic references, void/function pointers, raw `new`/`delete`, etc.
- **[05.function/](src/05.function/)** — Functions: scope & shadowing, overloading, default arguments, recursion, function pointers, lambdas, namespaces, `constexpr`/`consteval`, etc.
- **[06.operator/](src/06.operator/)** — Operators: arithmetic, logical, bitwise, increment/decrement, `sizeof`, etc.
- **[07.oop/](src/07.oop/)** — Object-oriented programming: classes, inheritance, polymorphism, copy/move constructors, operator overloading, static members, RAII, etc.
- **[08.io/](src/08.io/)** — Input/Output: `cin`/`cout`, file streams, string streams, binary I/O, formatting, etc.
- **[09.string/](src/09.string/)** — String handling: C-style strings, `std::string`, `std::string_view`, regex, etc.
- **[10.stl/](src/10.stl/)** — Standard Library: containers (`map`, `set`, `deque`, `list`), algorithms, ranges & views, `std::stack`/`std::queue`, `std::optional`/`std::variant`/`std::any`, etc.
- **[11.template/](src/11.template/)** — Template programming: specialization, variadic templates, fold expressions, non-type template parameters, concepts, etc.
- **[12.modern/](src/12.modern/)** — Modern C++ features: modules, ranges, `std::numeric`, structured bindings, three-way comparison, concepts, `std::format`, etc.
- **[13.preprocess/](src/13.preprocess/)** — Preprocessor: macros, function-like macros, `#undef`, `#if defined()`, stringizing, token pasting, `#pragma`, include guards, etc.
- **[14.exception/](src/14.exception/)** — Exception handling: `try`/`catch`, rethrow, custom exceptions, `noexcept`, etc.
- **[15.math/](src/15.math/)** — Math utilities: random numbers, complex numbers, bit manipulation, `numeric_limits`, `valarray`, etc.
- **[16.concurrency/](src/16.concurrency/)** — Concurrency: threads, mutexes, atomics, `std::async`, condition variables, semaphores, `std::jthread`, etc.
- **[17.filesystem/](src/17.filesystem/)** — Filesystem: paths, directory operations, recursive directory iteration, space info, etc.
- **[18.process/](src/18.process/)** — Process utilities: `std::abort`, signal handling, `std::getenv`, `std::system`, etc.

## Development Environment

The recommended way to build and run examples is inside the VS Code dev container for the best compatibility.

If you prefer to build on Windows natively, a few extra steps are needed to get both the compiler and the Clang language server working correctly:

1. Install `clang-cl`.
2. Generate a `compile_commands.json` for Clangd. If no `compile_commands.json` exists (or you need to regenerate it), run:
   ```sh
   xmake project -k compile_commands
   ```
   Or use the alternate xmake config if needed:
   ```sh
   xmake project -k compile_commands -F xmake-just-for-clangd-work.lua
   ```
3. Restart the Clang language server in VS Code. If it still doesn't work, build a few files first so the standard library module cache is populated:
   ```sh
   xmake run 01.basic_01.hello_world -F xmake-just-for-clangd-work.lua
   ```
   After that the language server should function properly.

import std; // C++23 standard library module — replaces #include <...>

// C++20/23 Modules replace the traditional preprocessor #include model:
// - Faster compilation: modules are pre-compiled, not re-parsed per TU
// - No header guards needed: modules are imported once
// - Better isolation: module linkage prevents macro leakage
// - Named modules: 'export module mylib;' + 'import mylib;' (requires build system support)
//
// This file demonstrates importing the standard library as a module.
// For custom named modules, see your build system's module support (CMake 3.28+, xmake, etc.)

int main()
{
    std::println("I'm using C++23 modules!");
    std::println("std::println comes from 'import std;' — no #include needed.");
    std::println("__cpp_modules: {}", __cpp_modules);
}

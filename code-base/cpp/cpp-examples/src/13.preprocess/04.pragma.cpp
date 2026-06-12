import std;

// #pragma once — non-standard but widely supported, simpler and faster
// Traditional include guard — standard C/C++, works everywhere
// Both prevent double inclusion; use #pragma once in modern projects,
// use traditional guards when portability is critical.
#ifndef DEMO_PRAGMA_HPP
#define DEMO_PRAGMA_HPP
constexpr int demo_value = 42;
#endif

#pragma message("Compiling pragma and preprocessor demo")

// #pragma GCC diagnostic — suppress or elevate warnings per-region
// (Clang also supports this syntax)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
int unused_var = 0; // no warning here
#pragma GCC diagnostic pop

// #error and #warning — force a compilation error or warning
// #error This branch is disabled; enable it to stop compilation.
// #warning This is a C++23 compile-time warning.

#if 0
#error This branch is disabled; enable it to stop compilation.
#endif

// #line changes __LINE__ and __FILE__ from this point onward
#line 100 "generated_config.hpp"
constexpr int  generated_line = __LINE__;
constexpr auto generated_file = __FILE__;
#line 20 "04.pragma.cpp"

int main()
{
    std::println("include guard value: {}", demo_value);
    std::println("generated location: {}:{}", generated_file, generated_line);
    std::println("current file: {}", __FILE__);
    std::println("current line: {}", __LINE__);
    std::println("build date: {}", __DATE__);
    std::println("__cplusplus: {} (202100L = C++23)", __cplusplus);
}

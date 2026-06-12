import std;

using namespace std::string_literals;

int main()
{
    // std::any — type-erased container (C++17), can hold std::any copyable type
    std::any a = 42;
    std::println("int: {}", std::any_cast<int>(a));

    a = 3.14;
    std::println("double: {}", std::any_cast<double>(a));

    a = "hello"s;
    std::println("std::string: {}", std::any_cast<std::string>(a));

    // Check type before casting
    a = 100;
    if (a.type() == typeid(int)) { std::println("It's an int: {}", std::any_cast<int>(a)); }

    // std::any_cast with pointer — returns nullptr on type mismatch
    a        = "world"s;
    auto* ps = std::any_cast<std::string>(&a);
    auto* pi = std::any_cast<int>(&a);
    std::println("std::string*: {}, int*: {}", static_cast<void*>(ps), static_cast<void*>(pi));

    // has_value / reset
    std::println("has_value: {}", a.has_value());
    a.reset();
    std::println("after reset: has_value = {}", a.has_value());
}

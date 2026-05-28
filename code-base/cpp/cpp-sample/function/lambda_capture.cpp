#include <print>

using namespace std;

int main()
{
    auto i{10};
    auto foo{[]() {
        // Lambdas cannot access local variables unless captured
        // std::println("i={}", i);
    }};

    // Lambda captures by const value
    auto bar{[i]() {
        std::println("i={}", i);
    }};

    bar();

    // Mutable capture
    auto goo{[i]() mutable {
        std::println("i={}", --i);
    }};
    goo();
    goo();
    std::println("now outer i is {}", i);

    // Capture by reference
    auto moo{[&i]() {
        i = 100;
        std::println("i={}", i);
    }};

    moo();
    std::println("now outer i is {}", i);

    // Capture all used variables by value
    auto hoo([=]() {
        std::println("capture by value: {}", i);
    });
    hoo();

    // Capture all used variables by reference
    auto joo([&]() {
        i = 600;
        std::println("capture by reference: {}", i);
    });
    joo();
}

#include <print>

using namespace std;

int main()
{
    auto i{10};
    auto foo{[]() {
        // lambdas cannot access the local variables unless it was captured
        // std::println("i={}", i);
    }};

    // lambda captures by const value
    auto bar{[i]() {
        std::println("i={}", i);
    }};

    bar();

    // mutable captures
    auto goo{[i]() mutable {
        std::println("i={}", --i);
    }};
    goo();
    goo();
    std::println("now outer i is {}", i);

    // captures by reference
    auto moo{[&i]() {
        i = 100;
        std::println("i={}", i);
    }};

    moo();
    std::println("now outer i is {}", i);

    // auto capture all used variables by value
    auto hoo([=]() {
        std::println("capture by value: {}", i);
    });
    hoo();

    // auto capture all used variable by reference
    auto joo([&]() {
        i = 600;
        std::println("capture by reference: {}", i);
    });
    joo();
}

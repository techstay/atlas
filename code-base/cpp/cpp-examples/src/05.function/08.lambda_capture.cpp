import std;

int main()
{
    auto i{10};

    auto foo{[]()
             {
                 // Lambdas cannot access outer locals unless captured
                 // std::println("i={}", i); // error: i is not captured
             }};
    foo();

    // Capture by value — copy is const inside the lambda
    auto bar{[i]() { std::println("capture by value: i={}", i); }};
    bar();

    // mutable allows modifying a by-value capture without affecting the outer variable
    auto goo{[i]() mutable { std::println("mutable capture: i={}", --i); }};
    goo();
    goo();
    std::println("outer i after mutable captures: {}", i);

    // Capture by reference — modifies the outer variable
    auto moo{[&i]()
             {
                 i = 100;
                 std::println("capture by reference: i={}", i);
             }};
    moo();
    std::println("outer i after reference capture: {}", i);

    // Init capture (C++14): move or compute a value into the closure
    auto hoo{[id = i + 1]() { std::println("init capture: id={}", id); }};
    hoo();

    // [=] and [&] capture everything used; prefer explicit captures in new code
    auto joo([=]() { std::println("capture all by value: i={}", i); });
    joo();

    auto koo(
        [&]()
        {
            i = 600;
            std::println("capture all by reference: i={}", i);
        });
    koo();
    std::println("outer i after capture-all: {}", i);
}

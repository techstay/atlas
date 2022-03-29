#include <iostream>

using namespace std;

int main()
{
    auto i{10};
    auto foo{[]() {
        // lambdas cannot access the local variables unless it was captured
        // cout << "i=" << i << endl;
    }};

    // lambda captures by const value
    auto bar{[i]() {
        cout << "i=" << i << endl;
    }};

    bar();

    // mutable captures
    auto goo{[i]() mutable {
        cout << "i=" << --i << endl;
    }};
    goo();
    goo();
    cout << "now outer i is " << i << endl;

    // captures by reference
    auto moo{[&i]() {
        i = 100;
        cout << "i=" << i << endl;
    }};

    moo();
    cout << "now outer i is " << i << endl;

    // auto capture all used variables by value
    auto hoo([=]() {
        cout << "capture by value: " << i << endl;
    });
    hoo();

    // auto capture all used variable by reference
    auto joo([&]() {
        i = 600;
        cout << "capture by reference: " << i << endl;
    });
    joo();
}

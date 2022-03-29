#include <iostream>

using namespace std;

// structs are classes which fields and methods are all public
// of course you can add private modifier
// to make them unaccessible outside the class
struct Employee
{
    string_view name{};
    int age{};
    double wage{};
};

int main()
{
    auto p1 = Employee{"techstay", 18, 3'000};
    // designated initializers, available in c++20
    auto p2 = Employee{.name = "lisa", .age = 28, .wage = 8'000};
}

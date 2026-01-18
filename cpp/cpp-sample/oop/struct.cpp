#include <iostream>

using namespace std;

// Structs are classes whose members are public by default
// You can add private/protected modifiers to restrict access
struct Employee
{
    string_view name{};
    int age{};
    double wage{};
};

int main()
{
    auto p1 = Employee{"techstay", 18, 3'000};
    // Designated initializers (available since C++20)
    auto p2 = Employee{.name = "lisa", .age = 28, .wage = 8'000};
}

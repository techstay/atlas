import std;

void print_grade(int marks)
{
    // C++17 switch with init-statement: `grade` is scoped to the switch
    // and bound to `marks / 10` before the controlling expression runs.
    switch (int grade = marks / 10; grade)
    {
    case 6:
        std::println("marks =\t{}:\tpassed", marks);
        break;
    case 7:
    case 8:
        std::println("marks =\t{}:\tgood", marks);
        break;
        // Multiple cases can be combined
    case 9:
        // The [[fallthrough]] attribute indicates that the following
        // fallthrough is intentional
        [[fallthrough]];
    case 10:
        std::println("marks =\t{}:\texcellent", marks);
        break;
        // Default clause executes if no other cases match
    default:
        std::println("marks =\t{}:\tfailed", marks);
    }
}

int main()
{
    print_grade(55);  // failed
    print_grade(60);  // passed
    print_grade(75);  // good
    print_grade(85);  // good
    print_grade(95);  // excellent
    print_grade(100); // excellent
}

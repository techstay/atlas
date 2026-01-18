#include <print>

using namespace std;

int main()
{
    auto marks = 60;
    switch (marks / 10)
    {
    case 6:
        std::println("passed");
        break;
    case 7:
    case 8:
        std::println("good");
        break;
        // multiple situations can be combined together
    case 9:
        // the fallthrough attribute is used to indicate that the following
        // fallthrough is intentional
        [[fallthrough]];
    case 10:
        std::println("excellent");
        break;
        // default clauses will be executed if others fallthrough
    default:
        std::println("failed");
    }
}

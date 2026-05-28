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
        // Multiple cases can be combined
    case 9:
        // The [[fallthrough]] attribute indicates that the following
        // fallthrough is intentional
        [[fallthrough]];
    case 10:
        std::println("excellent");
        break;
        // Default clause executes if no other cases match
    default:
        std::println("failed");
    }
}

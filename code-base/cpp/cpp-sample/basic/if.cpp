#include <print>

using namespace std;

int main(int argc, const char **argv)
{
    // If statement
    auto marks = 80;
    if (marks >= 60)
    {
        std::println("passed");
    }

    marks = 40;
    // If-else statement
    if (marks < 60)
    {
        std::println("failed");
    }
    else
    {
        std::println("passed");
    }

    // If-else-if statement
    marks = 100;
    if (marks < 60)
    {
        std::println("failed");
    }
    else if (marks >= 60 && marks < 100)
    {
        std::println("good");
    }
    else
    {
        std::println("very good!");
    }
    return 0;
}

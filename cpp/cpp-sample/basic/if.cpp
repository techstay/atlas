#include <print>

using namespace std;

int main(int argc, const char **argv)
{
    // if statements
    auto marks = 80;
    if (marks >= 60)
    {
        std::println("passed");
    }

    marks = 40;
    // if else statements
    if (marks < 60)
    {
        std::println("failed");
    }
    else
    {
        std::println("passed");
    }

    // if else if statements
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
import std;

int main()
{
    // If statement
    auto marks = 80;
    if (marks >= 60) { std::println("passed"); }

    marks = 40;
    // If-else statement
    if (marks < 60) { std::println("failed"); }
    else
    {
        std::println("passed");
    }

    // If-else-if statement
    marks = 100;
    if (marks < 60) { std::println("failed"); }
    // Reaching this branch already implies marks >= 60, so only the upper
    // bound needs to be checked — that is the point of an else-if chain.
    else if (marks < 100) { std::println("good"); }
    else
    {
        std::println("very good!");
    }
}

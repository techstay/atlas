#include <print>

using namespace std;

int main(int argc, const char **argv)
{
    bool foo = true;
    bool bar = false;

    // Booleans print as 1 and 0 by default
    std::println("{} {}", foo, bar);

    // Use conditional operator to print "true" and "false" as text
    std::println("{} {}", foo ? "true" : "false", bar ? "true" : "false");
    return 0;
}
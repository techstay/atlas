#include <print>

using namespace std;

int main(int argc, const char **argv)
{
    bool foo = true;
    bool bar = false;
    std::println("{} {}", foo, bar);
    // to print true and false as text
    std::println("{} {}", foo ? "true" : "false", bar ? "true" : "false");
    return 0;
}
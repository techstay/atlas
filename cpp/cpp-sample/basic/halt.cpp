#include <print>

using namespace std;

void before_exit()
{
    println("before exiting, we should do some cleanup work");
}

int main()
{
    println("do something...");

    // Register cleanup function
    atexit(before_exit);

    exit(0);

    println("This will not be executed since the program has terminated");
}

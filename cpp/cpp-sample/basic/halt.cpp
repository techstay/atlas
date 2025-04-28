#include <print>

using namespace std;

void before_exit()
{
    println("before exiting, we should do some cleanup work");
}

int main()
{
    println("do something...");
    // specifying cleanup functions
    atexit(before_exit);

    exit(0);

    println("this will be executed since the program is terminated");
}

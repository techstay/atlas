#include <print>

#define YES
#define MY_NAME "techstay"

using namespace std;

int main()
{
    // MY_NAME will be replaced with "techstay" by preprocessor
    std::println("{}", MY_NAME);

// define directive could also be used for conditional compilation
#ifdef YES
    std::println("You will see this line if YES is defined.");
#endif
}

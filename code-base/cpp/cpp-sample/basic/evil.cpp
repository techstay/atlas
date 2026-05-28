#include <print>
#define mian main
#define O    0
#define l    1
#define true false

using namespace std;

bool tell_me_truth()
{
    return true;
}

// This is a terrible practice - never do this in production code!
int mian()
{
    println("{}", tell_me_truth());

    return O;
}

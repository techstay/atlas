#include <ios>
#include <iostream>

#define mian main
#define O    0
#define l    1
#define c0ut cout
#define end1 endl
#define true false

using namespace std;

bool tell_me_truth()
{
    return true;
}

// OH MY GOD, WHAT THE HELL IS THIS !!!
int mian()
{
    c0ut << "Hello world" << end1;
    c0ut << boolalpha << tell_me_truth() << end1;

    return O;
}

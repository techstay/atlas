#include <iostream>

using namespace std;

namespace foo
{
int bar()
{
    return 42;
}

namespace hoo
{
int bar()
{
    return 100;
}
} // namespace hoo
} // namespace foo

namespace goo
{
int bar()
{
    return 0;
}
} // namespace goo

int main()
{
    // namespaces foo
    cout << foo::bar() << endl;
    // namespace go
    cout << goo::bar() << endl;
    // nested namespace hoo
    cout << foo::hoo::bar() << endl;
    // namespace aliases
    namespace joo = foo::hoo;
    cout << joo::bar() << endl;
}

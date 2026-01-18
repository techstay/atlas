#include <print>

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
    std::println("{}", foo::bar());
    // namespace go
    std::println("{}", goo::bar());
    // nested namespace hoo
    std::println("{}", foo::hoo::bar());
    // namespace aliases
    namespace joo = foo::hoo;
    std::println("{}", joo::bar());
}

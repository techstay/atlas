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
    // Use namespace foo
    std::println("{}", foo::bar());
    // Use namespace goo
    std::println("{}", goo::bar());
    // Use nested namespace hoo
    std::println("{}", foo::hoo::bar());
    // Namespace alias
    namespace joo = foo::hoo;
    std::println("{}", joo::bar());
}

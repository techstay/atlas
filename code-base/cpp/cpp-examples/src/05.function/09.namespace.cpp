import std;

namespace foo
{
int bar() { return 42; }

namespace hoo
{
int bar() { return 100; }
} // namespace hoo
} // namespace foo

// C++17 nested namespace syntax
namespace baz
{
namespace qux
{
int bar() { return 200; }
} // namespace qux
} // namespace baz

namespace goo
{
int bar() { return 0; }
} // namespace goo

namespace lib
{
inline namespace v2
{
int api() { return 2; }
} // namespace v2
} // namespace lib

namespace
{
int internal_helper() { return 999; }
} // namespace

int main()
{
    std::println("foo::bar() = {}", foo::bar());
    std::println("goo::bar() = {}", goo::bar());
    std::println("foo::hoo::bar() = {}", foo::hoo::bar());
    std::println("baz::qux::bar() = {}", baz::qux::bar());

    // inline namespace: lib::api() resolves to lib::v2::api()
    std::println("lib::api() = {}", lib::api());

    std::println("internal_helper() = {}", internal_helper());

    // Namespace alias
    namespace joo = foo::hoo;
    std::println("joo::bar() = {}", joo::bar());

    // using namespace imports all names — avoid in headers; limited scope is acceptable
    {
        using namespace goo;
        std::println("using namespace goo: bar() = {}", bar());
    }
}

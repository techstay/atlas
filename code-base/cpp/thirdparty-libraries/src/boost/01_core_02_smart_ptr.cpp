#include <boost/make_shared.hpp>
#include <boost/smart_ptr.hpp>
#include <print>
#include <string>

int main()
{
    // shared_ptr
    auto sp = boost::make_shared<std::string>("hello");
    std::println("shared_ptr: {}, use_count: {}", *sp, sp.use_count());

    // weak_ptr
    boost::weak_ptr<std::string> wp = sp;
    if (auto locked = wp.lock()) { std::println("weak_ptr locked: {}", *locked); }
    std::println("use_count after weak: {}", sp.use_count());

    // scoped_ptr
    boost::scoped_ptr<int> scp(new int(42));
    std::println("scoped_ptr: {}", *scp);

    return 0;
}

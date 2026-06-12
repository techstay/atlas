#include <boost/dynamic_bitset.hpp>
#include <print>

int main()
{
    // construction
    boost::dynamic_bitset<> bs(8);
    bs.set(0);
    bs.set(3);
    bs.set(7);
    std::println("count: {}", bs.count());
    std::println("any: {}", bs.any());

    // set / reset / flip
    bs.flip(1);
    bs.reset(3);
    std::println("after flip(1) reset(3), count: {}", bs.count());

    // count / any / none / all
    std::println("none: {}", bs.none());

    // bitwise ops
    boost::dynamic_bitset<> a(4);
    a.set(0);
    a.set(3);
    boost::dynamic_bitset<> b(4);
    b.set(1);
    b.set(3);
    auto c = a | b;
    std::println("a|b count: {}", c.count());
    auto d = a & b;
    std::println("a&b count: {}", d.count());

    // resize
    bs.resize(12);
    std::println("after resize(12), size: {}", bs.size());

    // find_first / find_next
    std::println("find_first: {}", bs.find_first());
    std::println("find_next(0): {}", bs.find_next(0));

    // to_ulong
    boost::dynamic_bitset<> small(8);
    small.set(0);
    small.set(2);
    std::println("to_ulong: {}", small.to_ulong());

    return 0;
}

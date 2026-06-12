#include <boost/circular_buffer.hpp>
#include <print>

int main()
{
    boost::circular_buffer<int> cb(5);

    // push_back
    for (int i = 1; i <= 7; ++i)
    {
        cb.push_back(i);
        std::println("push {} -> size={}, capacity={}", i, cb.size(), cb.capacity());
    }

    // overflow: oldest items dropped
    std::print("contents: ");
    for (auto v : cb) { std::print("{} ", v); }
    std::println("");

    std::println("front: {}, back: {}", cb.front(), cb.back());

    // linearize
    std::println("linearize ok: {}", cb.linearize() != nullptr);

    // full check
    std::println("full: {}", cb.full());

    // push_front
    cb.push_front(0);
    std::print("after push_front(0): ");
    for (auto v : cb) { std::print("{} ", v); }
    std::println("");

    return 0;
}

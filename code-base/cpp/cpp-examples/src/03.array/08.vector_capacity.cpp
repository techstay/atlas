import std;

int main()
{
    std::vector<int> v;

    std::println("start:  size={}, capacity={}", v.size(), v.capacity());

    // reserve — pre-allocate; subsequent push_backs avoid reallocation
    v.reserve(100);
    std::println("after reserve(100):  size={}, capacity={}", v.size(), v.capacity());

    // push_back grows size, not capacity (until we hit the reserved ceiling)
    for (int i = 0; i < 5; ++i) { v.push_back(i); }
    std::println("after 5 push_backs:  size={}, capacity={}", v.size(), v.capacity());

    // resize — changes size, value-initializes new elements
    v.resize(8, -1);
    std::println("after resize(8, -1): size={}, capacity={}", v.size(), v.capacity());

    // shrink_to_fit — non-binding request to release spare memory
    v.shrink_to_fit();
    std::println("after shrink_to_fit: size={}, capacity={}", v.size(), v.capacity());
}

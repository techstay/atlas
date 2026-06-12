import std;

int main()
{
    // std::deque supports fast ends and random access.
    std::deque<int> d{2, 3};
    d.push_front(1);
    d.push_back(4);
    std::println("deque[0] = {}, deque[2] = {}", d[0], d[2]);
    for (int x : d) { std::print("{} ", x); }
    std::println();
}

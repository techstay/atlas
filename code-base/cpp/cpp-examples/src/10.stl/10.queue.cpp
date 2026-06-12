import std;

int main()
{
    // std::queue defaults to using std::deque as the underlying container
    std::queue<std::string> q;
    q.push("first");
    q.push("second");
    std::println("queue front: {}, back: {}", q.front(), q.back());
    q.pop();
    std::println("queue front after pop: {}", q.front());
}

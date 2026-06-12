import std;

struct Resource
{
    Resource() { std::println("ctor"); }

    ~Resource() { std::println("dtor"); }
};

int main()
{
    auto p1 = std::make_shared<Resource>();
    std::println("use_count = {}", p1.use_count());

    {
        auto p2 = p1; // shared ownership
        std::println("use_count = {}", p1.use_count());
    } // p2 destroyed, count decrements

    std::println("use_count = {}", p1.use_count());
    // p1 destroyed at end of scope → Resource freed
}

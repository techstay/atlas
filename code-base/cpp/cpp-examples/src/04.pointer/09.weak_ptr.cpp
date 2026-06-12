import std;

struct Resource
{
    Resource() { std::println("ctor"); }

    ~Resource() { std::println("dtor"); }
};

int main()
{
    auto                    sp = std::make_shared<Resource>();
    std::weak_ptr<Resource> wp = sp; // observe without owning

    std::println("expired={}, use_count={}", wp.expired(), wp.use_count());

    if (auto locked = wp.lock()) // obtain shared_ptr for safe access
    {
        std::println("accessed via weak_ptr");
    }

    sp.reset(); // last shared owner released
    std::println("expired={}", wp.expired());
}

import std;

struct Resource
{
    std::string name;

    Resource(std::string n) : name(std::move(n)) { std::println("ctor: {}", name); }

    ~Resource() { std::println("dtor: {}", name); }
};

int main()
{
    auto p1 = std::make_unique<Resource>("a");
    auto p2 = std::move(p1); // transfer ownership; p1 becomes null

    std::println("p1={}, p2->name={}", p1 ? "valid" : "null", p2->name);
    // p2 is destroyed automatically at end of scope
}

#include <print>
#include <memory>

using namespace std;

class Resource
{
  private:
    string_view str{};

  public:
    Resource(const string_view &str) : str{str}
    {
        std::println("Resource obtained: {}", str);
    }

    ~Resource()
    {
        std::println("Resource destroyed: {}", str);
    }

    friend void print(const Resource &r)
    {
        std::println("Resource({})", r.str);
    }
};

int main()
{
    weak_ptr<Resource> ptr = make_shared<Resource>("abc");
    auto count             = ptr.use_count();
    std::println("use count: {}", count);

    if (ptr.expired())
    {
        std::println("the pointer is expired");
    }

    auto actual_ptr = ptr.lock();
    if (actual_ptr)
        auto res = actual_ptr.get();
}

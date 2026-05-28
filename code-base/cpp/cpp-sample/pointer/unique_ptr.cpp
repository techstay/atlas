#include <print>
#include <memory>
#include <string_view>

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

template <typename T>
T foo(T t)
{
    return t;
}

int main()
{
    auto ptr  = make_unique<Resource>("abc");
    auto ptr2 = foo(std::move(ptr));
    print(*ptr2);

    // Release ownership and return raw pointer, ptr becomes null
    auto raw_ptr = ptr.release();

    // Reset pointer (no-op if already null)
    ptr.reset();
    // Reset with new resource (takes ownership)
    ptr.reset(new Resource("bbc"));
}

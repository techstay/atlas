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

    // returning the raw pointer and set ptr null
    auto raw_ptr = ptr.release();

    // releasing ptr
    ptr.reset();
    // reseting new ptr
    ptr.reset(new Resource("bbc"));
}

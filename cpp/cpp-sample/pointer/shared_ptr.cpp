#include <print>
#include <memory>

using namespace std;

class Resource
{
  public:
    Resource()
    {
        std::println("Resource obtained");
    }

    ~Resource()
    {
        std::println("Resource destroyed");
    }
};

template <typename T>
T foo(T t)
{
    return t;
}

int main()
{
    auto ptr  = make_shared<Resource>();
    auto ptr2 = foo(ptr);

    if (ptr)
    {
        std::println("pointer is valid, other operators can perform.");
    }
    else
    {
        std::println("pointer may have been released");
    }

    // obtaining raw pointer
    Resource *raw_ptr = ptr.get();

    // checking if pointer is unique
    bool is_unique = ptr.unique();
    std::println("ptr is unique: {}", is_unique ? "true" : "false");

    auto count = ptr.use_count();
    std::println("how many pointers are used? {}", count);

    // custom deleter
    auto deleter = [](Resource *p) {
        delete p;
    };

    auto ptr3 = shared_ptr<Resource>(new Resource(), deleter);
}

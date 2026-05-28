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
        std::println("Pointer is valid");
    }
    else
    {
        std::println("Pointer is null or expired");
    }

    // Get raw pointer without affecting ownership
    Resource *raw_ptr = ptr.get();

    // Check if this is the sole owner
    bool is_unique = ptr.unique();
    std::println("ptr is unique: {}", is_unique ? "true" : "false");

    // Get reference count
    auto count = ptr.use_count();
    std::println("Reference count: {}", count);

    // Custom deleter
    auto deleter = [](Resource *p) {
        delete p;
    };

    auto ptr3 = shared_ptr<Resource>(new Resource(), deleter);
}

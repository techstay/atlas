#include <print>

using namespace std;

template <typename T>
class Test
{
  private:
    T *ptr{};

  public:
    Test(T t) : ptr(new T{t})
    {
        std::println("constructor: {}", static_cast<const void*>(ptr));
    }

    // Copy constructor
    Test(const Test &t) : ptr(new T{*t.ptr})
    {
        std::println("copy constructor: {}", static_cast<const void*>(ptr));
    }

    Test &operator=(const Test &t)
    {
        delete ptr;
        ptr  = new T;
        *ptr = *t.ptr;
        std::println("copy assignment: {}", static_cast<const void*>(ptr));
        return *this;
    }

    // Move constructor
    Test(Test &&t) : ptr(t.ptr)
    {
        t.ptr = nullptr;
        std::println("move constructor: {}", static_cast<const void*>(ptr));
    }

    Test &operator=(Test &&t)
    {
        delete ptr;
        ptr   = t.ptr;
        t.ptr = nullptr;
        std::println("move assignment: {}", static_cast<const void*>(ptr));
        return *this;
    }

    friend void print(const Test &t)
    {
        std::println("Test(ptr={}, value={})", static_cast<const void*>(t.ptr), *t.ptr);
    }

    ~Test()
    {
        std::println("destructing: {}", static_cast<const void*>(ptr));
        delete ptr;
        ptr = nullptr;
    }
};

template <typename T>
T foo(T t)
{
    T temp{t};
    return temp;
}

int main()
{
    // Debug this line to observe copy and move semantics
    auto t1{Test{1}};
    t1 = foo(t1);
}

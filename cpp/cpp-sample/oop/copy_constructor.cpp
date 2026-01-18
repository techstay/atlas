#include <print>

using namespace std;

template <typename T>
class MyValue
{
  private:
    T value;

  public:
    // The explicit keyword prevents implicit type conversion
    explicit MyValue(const T &t)
    {
        value = t;
        std::println("constructor {{}}", t);
    }

    // The = delete specifier makes the function unavailable
    MyValue(char c) = delete;

    // Copy constructor
    MyValue(const MyValue &obj)
    {
        value = obj.value;
        std::println("copy constructor {{}}", value);
    }

    // Copy assignment operator
    MyValue &operator=(const MyValue &t)
    {
        // Self-assignment check
        if (this == &t)
            return *this;
        std::println("copy assignment operator {}", value);
        value = t.value;
        return *this;
    }

    friend void print(const MyValue &obj)
    {
        std::println("MyValue({})", obj.value);
    }

    ~MyValue()
    {
        std::println("destructor {{}}", value);
    }
};

auto foo(auto f)
{
    auto temp = f;
    return temp;
}

int main()
{
    auto obj = MyValue(5);
    // Calling foo will copy MyValue once
    // Returning from foo will copy MyValue again
    auto obj2 = foo(obj);

    // Copy assignment operator
    obj = MyValue(20);

    // Copy elision - the direct constructor is called in this case
    // The copy constructor is not even needed! (since C++17)
    auto obj3{MyValue(3.14)};
}

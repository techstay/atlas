#include <print>

using namespace std;

template <typename T>
class MyValue
{
  private:
    T value;

  public:
    // explicit makes constructors and operators ineligible for implicit type conversion
    explicit MyValue(const T &t)
    {
        value = t;
        std::println("constructor {{}}", t);
    }

    // delete makes the function unavailable
    MyValue(char c) = delete;

    // copy constructor
    MyValue(const MyValue &obj)
    {
        value = obj.value;
        std::println("copy constructor {{}}", value);
    }

    // assignment operator
    MyValue &operator=(const MyValue &t)
    {
        // self assignment check
        if (this == &t)
            return *this;
        std::println("assignment operator {}", value);
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
    // calling foo will make MyValue being copied once
    // returning of fool will make MyValue being copied twice
    auto obj2 = foo(obj);

    // assignment operator
    obj = MyValue(20);

    // copy elision, in this situation the direct constructor is called
    // the copy constructor is even not needed! (since c++17)
    auto obj3{MyValue(3.14)};
}

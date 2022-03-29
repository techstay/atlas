#include <iostream>
#include <ostream>

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
        cout << "constructor {" << t << "}" << endl;
    }

    // delete makes the function unavailable
    MyValue(char c) = delete;

    // copy constructor
    MyValue(const MyValue &obj)
    {
        value = obj.value;
        cout << "copy constructor {" << obj << "}" << endl;
    }

    // assignment operator
    MyValue &operator=(const MyValue &t)
    {
        // self assignment check
        if (this == &t)
            return *this;
        cout << "assignment operator " << t << endl;
        value = t.value;
        return *this;
    }

    friend ostream &operator<<(ostream &out, const MyValue &obj)
    {
        out << "MyValue(" << obj.value << ")";
        return out;
    }

    ~MyValue()
    {
        cout << "destructor {" << value << "}" << endl;
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

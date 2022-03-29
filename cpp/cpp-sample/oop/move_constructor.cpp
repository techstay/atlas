#include <iostream>
#include <ostream>

using namespace std;

template <typename T>
class Test
{
  private:
    T *ptr{};

  public:
    Test(T t) : ptr(new T{t})
    {
        cout << "constructor: " << ptr << endl;
    }

    // copy constructor
    Test(const Test &t) : ptr(new T{*t.ptr})
    {
        cout << "copy constructor: " << ptr << endl;
    }

    Test &operator=(const Test &t)
    {
        delete ptr;
        ptr  = new T;
        *ptr = *t.ptr;
        cout << "copy assignment: " << ptr << endl;
        return *this;
    }

    // move constructor
    Test(Test &&t) : ptr(t.ptr)
    {
        t.ptr = nullptr;
        cout << "move constructor: " << ptr << endl;
    }

    Test &operator=(Test &&t)
    {
        delete ptr;
        ptr   = t.ptr;
        t.ptr = nullptr;
        cout << "move assignment: " << ptr << endl;
        return *this;
    }

    friend ostream &operator<<(ostream &out, const Test &t)
    {
        out << "Test(ptr=" << t.ptr << ", value=" << *t.ptr << ")";
        return out;
    }

    ~Test()
    {
        cout << "destructing: " << ptr << endl;
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
    // debug this line will demonstrate how copy and move semantics work
    auto t1{Test{1}};
    t1 = foo(t1);
}

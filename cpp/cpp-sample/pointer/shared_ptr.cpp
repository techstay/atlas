#include <ios>
#include <iostream>
#include <memory>

using namespace std;

class Resource
{
  public:
    Resource()
    {
        cout << "Resource obtained" << endl;
    }

    ~Resource()
    {
        cout << "Resource destroyed" << endl;
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
        cout << "pointer is valid, other operators can perform." << endl;
    }
    else
    {
        cout << "pointer may have been released" << endl;
    }

    // obtaining raw pointer
    Resource *raw_ptr = ptr.get();

    // checking if pointer is unique
    bool is_unique = ptr.unique();
    cout << boolalpha << "ptr is unique: " << is_unique << endl;

    auto count = ptr.use_count();
    cout << "how many pointers are used? " << count << endl;

    // custom deleter
    auto deleter = [](Resource *p) {
        delete p;
    };

    auto ptr3 = shared_ptr<Resource>(new Resource(), deleter);
}

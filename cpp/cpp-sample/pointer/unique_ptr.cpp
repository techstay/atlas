#include <iostream>
#include <memory>
#include <ostream>
#include <string_view>

using namespace std;

class Resource
{
  private:
    string_view str{};

  public:
    Resource(const string_view &str) : str{str}
    {
        cout << "Resource obtained: " << str << endl;
    }

    ~Resource()
    {
        cout << "Resource destroyed: " << str << endl;
    }

    friend ostream &operator<<(ostream &out, const Resource &r)
    {
        out << "Resource(" << r.str << ")";
        return out;
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
    cout << *ptr2 << endl;

    // returning the raw pointer and set ptr null
    auto raw_ptr = ptr.release();

    // releasing ptr
    ptr.reset();
    // reseting new ptr
    ptr.reset(new Resource("bbc"));
}

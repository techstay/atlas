#include <iostream>
#include <memory>

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

int main()
{
    weak_ptr<Resource> ptr = make_shared<Resource>("abc");
    auto count             = ptr.use_count();
    cout << "use count: " << count << endl;

    if (ptr.expired())
    {
        cout << "the pointer is expired" << endl;
    }

    auto actual_ptr = ptr.lock();
    if (actual_ptr)
        auto res = actual_ptr.get();
}

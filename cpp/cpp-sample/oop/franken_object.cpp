#include <print>
#include <string_view>

using namespace std;

class Base
{
  protected:
    string_view name;

  public:
    Base(const string_view &name) : name{name}
    {
    }

    virtual void print() = 0;
};

class Derived : public Base
{
  private:
    string_view value;

  public:
    Derived(const string_view &name) : Base(name), value{name}
    {
    }

    void print()
    {
        std::println("name: {} value: {}", name, value);
    }
};

int main()
{
    Derived d1{"100"};
    Derived d2{"200"};

    // when instantiated, the base and derived parts are initialized with d2
    Base &base{d1};

    // when assigned, only the base parts is assigned
    // noting the frankenobject appears!
    base = d2;
    base.print();
}

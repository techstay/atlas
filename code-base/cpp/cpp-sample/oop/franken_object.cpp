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

    // When instantiated, both base and derived parts are initialized
    Base &base{d1};

    // When assigned, only the base part is assigned
    // Note: This creates a franken-object!
    base = d2;
    base.print();
}

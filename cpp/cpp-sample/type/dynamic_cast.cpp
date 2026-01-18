#include <print>

using namespace std;

class Base
{
  public:
    void print()
    {
        std::println("base class");
    }

    // make sure Base class has vtable which is required for dynamic_cast
    virtual void just_to_make_sure_the_code_compiles() = 0;
};

class Derived : public Base
{
  public:
    void print()
    {
        std::println("derived class");
    }

    void just_to_make_sure_the_code_compiles() override
    {
    }
};

int main()
{
    Base *ptr = new Derived();
    ptr->print();

    Derived *ptr2 = dynamic_cast<Derived *>(ptr);
    ptr2->print();
}

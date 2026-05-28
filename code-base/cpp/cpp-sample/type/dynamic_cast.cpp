#include <print>

using namespace std;

class Base
{
  public:
    void print()
    {
        std::println("base class");
    }

    // Virtual function ensures Base has a vtable, required for dynamic_cast
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
    // Base pointer actually pointing to Derived object
    Base *ptr = new Derived();
    ptr->print();

    // Safely downcast using runtime type information (RTTI)
    Derived *ptr2 = dynamic_cast<Derived *>(ptr);
    ptr2->print();
}

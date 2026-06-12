import std;

class Base
{
public:
    virtual ~Base() = default;

    void print() { std::println("base class"); }

    // Virtual function ensures Base has a vtable, required for dynamic_cast
    virtual void foo() = 0;
};

class Derived : public Base
{
public:
    void print() { std::println("derived class"); }

    void foo() override {}
};

int main()
{
    // Base pointer actually pointing to Derived object
    auto ptr = std::make_unique<Derived>();
    ptr->print();

    // Safely downcast using runtime type information (RTTI)
    Derived* ptr2 = dynamic_cast<Derived*>(ptr.get());
    if (ptr2) { ptr2->print(); }
    else
    {
        std::println("dynamic_cast failed — ptr does not point to a Derived object");
    }
}

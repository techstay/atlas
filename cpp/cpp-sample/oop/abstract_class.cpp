#include <print>
#include <string_view>

using namespace std;

// abstract class
class Animal
{
  private:
    string_view name;

  public:
    Animal(const string_view &name) : name{name}
    {
    }

    // this is a pure virtual method
    virtual void speak() = 0;
};

class Dog : public Animal
{
  private:
  public:
    Dog(const string_view &name) : Animal(name)
    {
    }

    void speak() override
    {
        std::println("wow wow");
    }
};

int main()
{
    auto dog = Dog{"dog"};
    dog.speak();

    // abstract classes cannot be instantiated
    // auto animal = Animal{"animal"};
}

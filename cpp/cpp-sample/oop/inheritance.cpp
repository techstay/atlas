#include <print>
#include <string_view>
#include <vector>

using namespace std;

class Person
{
  private:
    string_view name{};
    int age{};

  public:
    Person(const string_view &name = "", int age = 0)
    {
        this->name = name;
        this->age  = age;
    }

    void say_hello()
    {
        std::println("Hello");
    }

    virtual void introduce_self()
    {
        std::println("I'm a person.");
    }
};

class Employee : public Person
{
  private:
    double wage{};

  public:
    // calling base constructors
    Employee(const string_view &name = "", int age = 0, double wage = 0) : Person(name, age), wage{wage}
    {
    }

    void say_hello()
    {
        std::println("Hello, boss!");
    }

    // adding override specifier lets compilers report an error when no base virtual method was found
    // the final specifier forbidden other from overriding this method
    void introduce_self() override final
    {
        std::println("I'm an employee.");
    }
};

int main()
{
    auto p = Employee{"techstay", 18, 3'000};
    p.say_hello();
    // calling the base function
    p.Person::say_hello();

    // polymorphism
    vector<Person *> list{};
    list.push_back(new Person());
    list.push_back(&p);
    for (auto &ptr : list)
    {
        ptr->introduce_self();
    }
}

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
    // Call the base class constructor
    Employee(const string_view &name = "", int age = 0, double wage = 0) : Person(name, age), wage{wage}
    {
    }

    void say_hello()
    {
        std::println("Hello, boss!");
    }

    // The override specifier ensures a base virtual function exists
    // The final specifier prevents derived classes from overriding this function
    void introduce_self() override final
    {
        std::println("I'm an employee.");
    }
};

int main()
{
    auto p = Employee{"techstay", 18, 3'000};
    p.say_hello();
    // Call the base class function
    p.Person::say_hello();

    // Polymorphism
    vector<Person *> list{};
    list.push_back(new Person());
    list.push_back(&p);
    for (auto &ptr : list)
    {
        ptr->introduce_self();
    }
}

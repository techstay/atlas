import std;

class Person
{
private:
    std::string_view name{};
    int              age{};

public:
    Person(const std::string_view& name = "", int age = 0) : name{name}, age{age} {}

    virtual ~Person() = default;

    void say_hello() { std::println("Hello"); }

    virtual void introduce_self() { std::println("I'm a person."); }
};

class Employee : public Person
{
private:
    double wage{};

public:
    // Call the base class constructor
    Employee(const std::string_view& name = "", int age = 0, double wage = 0)
        : Person(name, age), wage{wage}
    {
    }

    void say_hello() { std::println("Hello, boss!"); }

    // The override specifier ensures a base virtual function exists
    // The final specifier prevents derived classes from overriding this function
    void introduce_self() override final { std::println("I'm an employee."); }
};

int main()
{
    auto p = Employee{"techstay", 18, 3'000};
    p.say_hello();
    // Call the base class function
    p.Person::say_hello();

    // Polymorphism
    std::vector<std::unique_ptr<Person>> list{};
    list.push_back(std::make_unique<Person>());
    list.push_back(std::make_unique<Employee>(p));
    for (auto& ptr : list) { ptr->introduce_self(); }
}

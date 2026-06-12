import std;

// Abstract class
class Animal
{
private:
    std::string_view name;

public:
    Animal(const std::string_view& name) : name{name} {}

    virtual ~Animal() = default;

    // Pure virtual function - makes this class abstract
    virtual void speak() = 0;
};

class Dog : public Animal
{
public:
    Dog(const std::string_view& name) : Animal(name) {}

    void speak() override { std::println("wow wow"); }
};

int main()
{
    auto dog = Dog{"dog"};
    dog.speak();

    // Abstract classes cannot be instantiated
    // auto animal = Animal{"animal"};
}

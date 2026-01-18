#include <print>

using namespace std;

class Class1
{
  private:
    int a{};
    int b{};

  protected:
    int c{100};

  public:
    int d{};
};

class Class2 : Class1
{
  public:
    void getC()
    {
        std::println("I can access the field c: {}", c);
    }
};

int main()
{
    // Private members are not accessible outside the class
    auto obj{Class1{}};
    // obj.a = 3;

    // Protected members are accessible only in derived classes
    auto obj2{Class2{}};
    obj2.getC();

    // Public members are accessible outside the class
    obj.d = 5;
}

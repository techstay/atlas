#include <iostream>

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
        cout << "I can access the field c: " << c << endl;
    }
};

int main()
{
    // private properties are not visible outside the class
    auto obj{Class1{}};
    // obj.a = 3;

    // protected properties are only visible in the derived classes
    auto obj2{Class2{}};
    obj2.getC();

    // public properties are visible outside the class
    obj.d = 5;
}

#include <iostream>

using namespace std;

class Foo
{
  private:
    // directly instantiating static inline members since c++17
    static inline int count{0};

  public:
    Foo()
    {
        count++;
    }

    ~Foo()
    {
        count--;
    }

    // static methods can be called with Foo::getCount() or obj.getCount()
    // but we prefer the former
    static int getCount()
    {
        return count;
    }
};

int main()
{
    for (int i = 0; i < 5; i++)
    {
        new Foo();
    }
    cout << "foo count: " << Foo::getCount() << endl;
}

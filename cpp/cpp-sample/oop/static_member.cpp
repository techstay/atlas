#include <print>

using namespace std;

class Foo
{
  private:
    // Directly initializing static inline members (available since C++17)
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

    // Static methods can be called with Foo::getCount() or obj.getCount()
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
    std::println("foo count: {}", Foo::getCount());
}

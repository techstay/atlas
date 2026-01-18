#include <print>
#include <typeinfo>

using namespace std;

template <typename T>
class Test
{
  private:
    T t;

  public:
    void print() const
    {
        std::println("{}", typeid(T).name());
    }
};

// Partial template specialization for double
template <>
class Test<double>
{
  private:
    double t;

  public:
    void print() const
    {
        std::println("I'm double, I'm different with others!");
    }
};

int main()
{
    auto test_int{Test<int>{}};
    auto test_double{Test<double>{}};
    auto test_longlong{Test<long long>{}};

    test_int.print();
    test_double.print();
    test_longlong.print();
}

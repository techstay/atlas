#include <iostream>

using namespace std;

template <typename T>
class Test
{
  private:
    T t;

  public:
    void print() const
    {
        cout << typeid(T).name() << endl;
    }
};

// partial template double specialization
template <>
class Test<double>
{
  private:
    double t;

  public:
    void print() const
    {
        cout << "I'm double, I'm different with others!" << endl;
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

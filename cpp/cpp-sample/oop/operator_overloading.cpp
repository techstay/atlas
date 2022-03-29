#include <ios>
#include <iostream>

using namespace std;

template <typename T>
class MyValue
{
  private:
    T value{};

  public:
    MyValue(T t) : value{t}
    {
    }

    MyValue(MyValue const &other) : MyValue(other.value)
    {
    }

    // overloading rational operators
    friend bool operator==(const MyValue<T> &a, const MyValue<T> &b)
    {
        return a.t == b.t;
    }

    friend bool operator!=(const MyValue<T> &a, const MyValue<T> &b)
    {
        return !(a == b);
    }

    friend bool operator>(const MyValue<T> &a, const MyValue<T> &b)
    {
        return a.value > b.value;
    }

    friend bool operator<(const MyValue<T> &a, const MyValue<T> &b)
    {
        return a.value < b.value;
    }

    friend bool operator<=(const MyValue<T> &a, const MyValue<T> &b)
    {
        return !(a > b);
    }

    friend bool operator>=(const MyValue<T> &a, const MyValue<T> &b)
    {
        return !(a < b);
    }

    // overloading arithmetic operators
    friend MyValue<T> operator+(const MyValue<T> &a, const MyValue<T> &b)
    {
        return MyValue(a.value + b.value);
    }

    friend MyValue<T> operator-(const MyValue<T> &a, const MyValue<T> &b)
    {
        return MyValue(a.value - b.value);
    }

    friend MyValue<T> operator*(const MyValue<T> &a, const MyValue<T> &b)
    {
        return MyValue(a.value * b.value);
    }

    friend MyValue<T> operator/(const MyValue<T> &a, const MyValue<T> &b)
    {
        return MyValue(a.value / b.value);
    }

    // overloading increment and decrement operators

    // prefix increment operator with no parameters
    MyValue<T> &operator++()
    {
        this->value++;
        return *this;
    }

    MyValue<T> &operator--()
    {
        this->value--;
        return *this;
    }

    // postfix increment operator requires a parameter but not uses it
    MyValue<T> operator++(T)
    {
        MyValue<T> temp{this->value};
        this->value++;
        return temp;
    }

    // overloading stream operators
    friend ostream &operator<<(ostream &out, const MyValue<T> &t)
    {
        out << "MyValue(" << t.value << ")";
        return out;
    }

    // overloading parenthesis operator
    // we implement accumulator function here
    MyValue &operator()(T t)
    {
        this->value += t;
        return *this;
    }

    // type cast operators
    operator double()
    {
        return static_cast<double>(this->value);
    }

    operator int()
    {
        return static_cast<int>(this->value);
    }

    // overloading unary operators
    MyValue<T> operator!()
    {
        return MyValue(-this->value);
    }
};

int main()
{
    auto a{MyValue{1}};
    auto b{MyValue{5}};
    cout << boolalpha;
    cout << a + b << endl;
    cout << "a>b? " << (a > b) << endl;
    cout << "a<b? " << (a < b) << endl;
    cout << "prefix increment: " << ++a << endl;
    cout << "postfix increment: " << b++ << endl;
    cout << "now b is " << b << endl;
    cout << "test parenthesis operator: " << a(10) << endl;
    cout << "type cast: " << static_cast<double>(a) << " " << static_cast<int>(b) << endl;
}

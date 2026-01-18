#include <print>

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

    // Overloading relational operators
    friend bool operator==(const MyValue<T> &a, const MyValue<T> &b)
    {
        return a.value == b.value;
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

    // Overloading arithmetic operators
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

    // Overloading increment and decrement operators

    // Prefix increment operator (no parameters)
    MyValue<T> &operator++()
    {
        this->value++;
        return *this;
    }

    // Prefix decrement operator (no parameters)
    MyValue<T> &operator--()
    {
        this->value--;
        return *this;
    }

    // Postfix increment operator (requires a dummy parameter)
    MyValue<T> operator++(T)
    {
        MyValue<T> temp{this->value};
        this->value++;
        return temp;
    }

    // Overloading output stream operator
    friend void print(const MyValue<T> &t)
    {
        std::println("MyValue({})", t.value);
    }

    // Overloading function call operator
    // Implementing an accumulator function
    MyValue &operator()(T t)
    {
        this->value += t;
        return *this;
    }

    // Type conversion operators
    operator double()
    {
        return static_cast<double>(this->value);
    }

    operator int()
    {
        return static_cast<int>(this->value);
    }

    // Overloading unary operators
    MyValue<T> operator!()
    {
        return MyValue(-this->value);
    }
};

int main()
{
    auto a{MyValue{1}};
    auto b{MyValue{5}};
    print(a + b);
    std::println("a>b? {}", (a > b) ? "true" : "false");
    std::println("a<b? {}", (a < b) ? "true" : "false");
    print(++a);
    print(b++);
    print(b);
    print(a(10));
    std::println("type cast: {} {}", static_cast<double>(a), static_cast<int>(b));
}

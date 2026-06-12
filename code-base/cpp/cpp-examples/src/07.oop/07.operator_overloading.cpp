import std;

template <typename T> class MyValue
{
private:
    T value{};

public:
    explicit MyValue(T t) : value{t} {}

    // Relational operators compare the wrapped value.
    friend bool operator==(const MyValue& a, const MyValue& b) { return a.value == b.value; }
    friend bool operator!=(const MyValue& a, const MyValue& b) { return !(a == b); }
    friend bool operator>(const MyValue& a, const MyValue& b) { return a.value > b.value; }
    friend bool operator<(const MyValue& a, const MyValue& b) { return b > a; }
    friend bool operator<=(const MyValue& a, const MyValue& b) { return !(a > b); }
    friend bool operator>=(const MyValue& a, const MyValue& b) { return !(a < b); }

    // Arithmetic operators return a new wrapped result.
    friend MyValue operator+(const MyValue& a, const MyValue& b)
    { return MyValue{a.value + b.value}; }
    friend MyValue operator-(const MyValue& a, const MyValue& b)
    { return MyValue{a.value - b.value}; }
    friend MyValue operator*(const MyValue& a, const MyValue& b)
    { return MyValue{a.value * b.value}; }
    friend MyValue operator/(const MyValue& a, const MyValue& b)
    { return MyValue{a.value / b.value}; }

    friend void print(const MyValue& v) { std::println("MyValue({})", v.value); }
};

int main()
{
    auto a{MyValue{12}};
    auto b{MyValue{4}};

    print(a + b);
    print(a - b);
    print(a * b);
    print(a / b);

    std::println("a == b: {}", a == b);
    std::println("a != b: {}", a != b);
    std::println("a > b: {}", a > b);
    std::println("a < b: {}", a < b);
    std::println("a <= b: {}", a <= b);
    std::println("a >= b: {}", a >= b);
}

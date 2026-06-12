import std;

template <typename T> class Counter
{
private:
    T value{};

public:
    explicit Counter(T start = {}) : value{start} {}

    // Prefix operators return the updated object.
    Counter& operator++()
    {
        ++value;
        return *this;
    }
    Counter& operator--()
    {
        --value;
        return *this;
    }

    // Postfix operators use int as the required dummy parameter.
    Counter operator++(int)
    {
        auto old{*this};
        ++(*this);
        return old;
    }

    Counter operator--(int)
    {
        auto old{*this};
        --(*this);
        return old;
    }

    // Function call operator works as an accumulator.
    Counter& operator()(T step)
    {
        value += step;
        return *this;
    }
    explicit operator T() const { return value; }
    explicit operator bool() const { return value != T{}; }
    bool     operator!() const { return value == T{}; }

    friend void print(const Counter& counter) { std::println("Counter({})", counter.value); }
};

int main()
{
    auto count{Counter{3}};

    print(++count);
    print(count++);
    print(count);
    print(--count);
    print(count--);
    print(count(10));

    std::println("as int: {}", static_cast<int>(count));
    std::println("as bool: {}", static_cast<bool>(count));
    std::println("is zero: {}", !Counter<int>{});
}

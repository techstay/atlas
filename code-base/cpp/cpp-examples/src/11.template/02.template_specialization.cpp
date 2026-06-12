import std;

template <typename T> class Test
{
private:
    T t;

public:
    void print() const { std::println("{}", typeid(T).name()); }
};

// Full/Explicit template specialization for double
template <> class Test<double>
{
private:
    double t;

public:
    void print() const { std::println("Full specialization: I'm double!"); }
};

// Partial template specialization for pointer types
template <typename T> class Test<T*>
{
public:
    void print() const { std::println("Partial specialization: I'm a pointer type!"); }
};

int main()
{
    auto test_int{Test<int>{}};
    auto test_double{Test<double>{}};
    auto test_longlong{Test<long long>{}};
    auto test_pointer{Test<int*>{}};

    test_int.print();
    test_double.print();
    test_longlong.print();
    test_pointer.print();
}

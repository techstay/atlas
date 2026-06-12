import std;

class Counter
{
    int count = 0;

public:
    // Return *this to enable method chaining
    Counter& increment()
    {
        count++;
        return *this;
    }

    Counter& decrement()
    {
        count--;
        return *this;
    }

    Counter& print()
    {
        std::println("count = {}", count);
        return *this;
    }

    // Compare this object with another
    bool is_equal(const Counter& other) const
    {
        return this == &other; // this is the address of the current object
    }
};

int main()
{
    Counter c1;
    // Method chaining via *this
    c1.increment().increment().increment().print();

    Counter c2;
    c2.decrement().decrement().print();

    // this pointer: comparing object addresses
    Counter& ref_c1 = c1;
    std::println("c1 == ref_c1: {}", c1.is_equal(ref_c1));
    std::println("c1 == c2:     {}", c1.is_equal(c2));
}

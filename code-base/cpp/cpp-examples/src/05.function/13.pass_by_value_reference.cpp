import std;

void pass_by_value(int x)
{
    x = 0;
    std::println("pass_by_value: x = {}", x);
}

void pass_by_reference(int& x)
{
    x = 100;
    std::println("pass_by_reference: x = {}", x);
}

void pass_by_const_reference(const int& x)
{
    // x = 100; // error: cannot assign to const reference
    std::println("pass_by_const_reference: x = {}", x);
}

int main()
{
    int value{42};

    pass_by_value(value);
    std::println("after pass_by_value: value = {}", value);

    pass_by_reference(value);
    std::println("after pass_by_reference: value = {}", value);

    pass_by_const_reference(value);
    std::println("after pass_by_const_reference: value = {}", value);
}

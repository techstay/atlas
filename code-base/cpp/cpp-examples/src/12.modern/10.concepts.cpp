import std;

// Define a concept for printable types
template <typename T>
concept Printable = requires(T t) {
    { std::print("{}", t) };
};

// Define a concept for numeric types
template <typename T>
concept Numeric = std::is_arithmetic_v<T>;

// Define a concept for containers
template <typename T>
concept Container = requires(T t) {
    typename T::value_type;
    t.begin();
    t.end();
    t.size();
};

// Use concepts as constraints
template <Numeric T> T square(T value) { return value * value; }

template <Container C>
    requires Printable<typename C::value_type>
void print_container(const C& c)
{
    for (const auto& item : c) { std::print("{} ", item); }
    std::println();
}

// Concept with requires clause
template <typename T>
    requires Numeric<T>
T absolute(T value)
{ return value < 0 ? -value : value; }

int main()
{
    std::println("square(5) = {}", square(5));
    std::println("square(3.14) = {}", square(3.14));

    std::println("abs(-42) = {}", absolute(-42));
    std::println("abs(3.14) = {}", absolute(3.14));

    std::vector<int> nums{1, 2, 3, 4, 5};
    print_container(nums);

    std::vector<std::string> words{"hello", "world"};
    print_container(words);
}

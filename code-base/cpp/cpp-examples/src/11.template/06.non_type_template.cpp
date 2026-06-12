import std;

// Using std::size_t for sizes is standard practice
template <typename T, std::size_t Size> class StaticArray
{
public:
    T data[Size]{};

    std::size_t size() const { return Size; }
};

// C++17 'auto' placeholder for NTTP (Non-Type Template Parameter)
template <auto Value> void show_value() { std::println("value = {}", Value); }

int main()
{
    StaticArray<int, 4> numbers{{1, 2, 3, 4}};

    std::println("array size = {}", numbers.size());
    std::println("first = {}", numbers.data[0]);

    show_value<42>();
    show_value<'A'>();

    // C++20 allows floating-point numbers as NTTPs
    show_value<3.14>();
}

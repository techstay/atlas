import std;

int main()
{
    // std::array knows its size at compile time
    std::array<int, 5> a1{1, 2, 3}; // remaining elements are value-initialized

    // C++17 CTAD — size is deduced from the initializer list
    std::array a2{1, 2, 3, 4, 5};

    std::println("a1: size={}", a1.size());
    std::println("a2: size={}", a2.size());
}

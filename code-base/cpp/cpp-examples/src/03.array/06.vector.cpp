import std;

int main()
{
    // Empty vector
    std::vector<int> v1;

    // Vector with 5 default-initialized elements (0 for int)
    std::vector<int> v2(5);

    // Vector with size 10, all initialized to 1
    std::vector<int> v3(10, 1);

    // Vector initialization via initializer list
    std::vector<int> v4{1, 2, 3, 4, 5};

    std::println("v1 size: {}", v1.size());
    std::println("v2 size: {}", v2.size());
    std::println("v3 size: {}", v3.size());
    std::println("v4 size: {}", v4.size());

    // Dynamic resizing
    v1.resize(10);
    std::println("v1 after resize: {}", v1.size());

    // Dynamic element insertion
    std::vector<int> v5{};
    for (int i = 0; i < 10; i++) { v5.push_back(i); }
    std::println("v5 size after push_back: {}", v5.size());
}

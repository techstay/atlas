import std;

int main()
{
    int* value = new int{42};
    std::println("single object = {}", *value);
    delete value; // new -> delete

    int* numbers = new int[3]{1, 2, 3};
    for (int i = 0; i < 3; ++i) { std::println("numbers[{}] = {}", i, numbers[i]); }
    delete[] numbers; // new[] -> delete[]

    // Note: prefer std::make_unique / std::vector in modern C++.
}

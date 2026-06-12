import std;

// std::function erases the callable type and may allocate; prefer templates for hot paths
void foo(const std::function<void()>& callback) { callback(); }

// Abbreviated function template (C++20): preserves the concrete lambda type, no type erasure
void bar(const auto& callback) { callback(); }

// See also: 11.template/01.function_template.cpp for explicit function templates
template <typename T> void print_vector(const std::vector<T>& v)
{
    std::print("[");
    bool first{true};
    for (const auto& e : v)
    {
        if (!first) { std::print(" "); }
        std::print("{}", e);
        first = false;
    }
    std::println("]");
}

int main()
{
    // Lambda with explicit return type
    auto sum = [](int a, int b) -> int { return a + b; };
    std::println("sum: {}", sum(2, 3));

    // Generic lambda: parameter types are deduced per call site
    auto generic_add = [](auto a, auto b) { return a + b; };
    std::println("generic_add(int): {}", generic_add(2, 3));
    std::println("generic_add(double): {}", generic_add(1.5, 2.5));

    foo([]() { std::println("foo via std::function"); });

    bar([]() { std::println("bar via abbreviated function template"); });

    auto list{std::vector{5, 4, 6, 2, 3, 1, 8}};

    std::sort(list.begin(), list.end(), [](auto a, auto b) { return a < b; });
    std::print("ascending: ");
    print_vector(list);

    std::sort(list.begin(), list.end(), [](auto a, auto b) { return a > b; });
    std::print("descending: ");
    print_vector(list);
}

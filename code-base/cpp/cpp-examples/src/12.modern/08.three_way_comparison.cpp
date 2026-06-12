import std;

// C++20 three-way comparison (spaceship operator)
struct Version
{
    int major;
    int minor;
    int patch;

    // Auto-generates ==, !=, <, <=, >, >= via <=>
    auto operator<=>(const Version&) const = default;
};

int main()
{
    Version v1{1, 2, 3};
    Version v2{2, 0, 0};
    Version v3{1, 2, 3};

    // All six comparison operators are auto-generated
    std::println("v1 <  v2: {}", v1 < v2);
    std::println("v1 <= v2: {}", v1 <= v2);
    std::println("v1 >  v2: {}", v1 > v2);
    std::println("v1 == v3: {}", v1 == v3);
    std::println("v1 != v2: {}", v1 != v2);

    // The spaceship operator can also be called directly
    auto result = v1 <=> v2;
    if (result < 0) { std::println("v1 is less than v2"); }
    else if (result > 0) { std::println("v1 is greater than v2"); }
    else
    {
        std::println("v1 equals v2");
    }

    // Built-in types also support <=>
    auto cmp = 42 <=> 24;
    if (cmp == std::strong_ordering::greater) { std::println("42 > 24"); }
    static_assert((3.14 <=> 3.14) == std::partial_ordering::equivalent);
}

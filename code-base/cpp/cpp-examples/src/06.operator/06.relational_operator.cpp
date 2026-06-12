import std;

int main()
{
    // Relational operators
    bool result;

    result = 1 < 2; // less than
    std::println("1 < 2  = {}", result);

    result = 1 > 2; // greater than
    std::println("1 > 2  = {}", result);

    result = 1 <= 2; // less than or equal
    std::println("1 <= 2 = {}", result);

    result = 1 >= 2; // greater than or equal
    std::println("1 >= 2 = {}", result);

    result = 1 == 2; // equal
    std::println("1 == 2 = {}", result);

    result = 1 != 2; // not equal
    std::println("1 != 2 = {}", result);
}

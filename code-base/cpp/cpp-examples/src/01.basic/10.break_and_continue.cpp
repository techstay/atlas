import std;

int main()
{
    // Break statement
    for (auto i{0}; i <= 10; i++)
    {
        // Halt the loop when i is 5
        if (i == 5) { break; }
        std::print("{} ", i);
    }
    std::println();

    // Continue statement
    for (auto i{0}; i <= 10; i++)
    {
        // Skip the value 5
        if (i == 5) { continue; }
        std::print("{} ", i);
    }
    std::println();
}

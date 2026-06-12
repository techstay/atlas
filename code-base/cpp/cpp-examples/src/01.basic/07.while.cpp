import std;

int main()
{
    // Basic while loop: execute the body while the condition holds.
    auto i = 0;
    while (i <= 5)
    {
        std::print("{} ", i);
        i++;
    }
    std::println();
}

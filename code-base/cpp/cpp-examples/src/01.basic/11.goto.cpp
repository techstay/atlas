import std;

int main()
{
    auto i{0};
    // Simulate a for loop using goto
START:
    if (i <= 5)
    {
        i++;
        goto START;
        std::println("This will never be printed because of the goto above.");
    }
    else
    {
        std::println("now i is {}", i);
        std::println("Never use goto!");
    }
}

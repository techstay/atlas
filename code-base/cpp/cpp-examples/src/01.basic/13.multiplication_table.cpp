import std;

int main()
{
    // 9x9 multiplication table
    for (auto a = 1; a <= 9; ++a)
    {
        for (auto b = 1; b <= a; ++b)
        {
            // Print the multiplication result in a formatted way
            std::print("{}*{}={}\t", b, a, a * b);
        }
        std::println();
    }
}

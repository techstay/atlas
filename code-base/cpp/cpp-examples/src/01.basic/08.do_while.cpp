import std;

int main()
{
    // Basic do-while: like while, but the body always executes at least
    // once because the condition is checked AFTER the body runs.
    auto i = 0;
    do
    {
        std::print("{} ", i);
        i++;
    } while (i <= 5);
    std::println();
}

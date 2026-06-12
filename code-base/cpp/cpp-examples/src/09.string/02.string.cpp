import std;

int main()
{
    std::string s{};
    std::println("Input a string:");

    // ws manipulator skips leading whitespace
    std::getline(std::cin >> std::ws, s);

    std::println("You typed:   {}", s);
    std::println("length:      {}", std::ssize(s));
    std::println("empty:       {}", s.empty());
}

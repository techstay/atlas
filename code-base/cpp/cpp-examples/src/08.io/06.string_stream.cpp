import std;

int main()
{
    const std::string some_lines = "I have a dream. "
                                   "You have a dream too.\n"
                                   "We all have dreams.";

    std::istringstream input(some_lines);
    for (std::string word; input >> word;) { std::print("{} ", word); }
    std::println();

    std::ostringstream output;
    output << std::format("1 + 1 = {}\n", 2);
    output << std::format("2 + 2 = {}\n", 4);
    std::println("{}", output.str());
}

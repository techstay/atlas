#include <print>
#include <sstream>

using namespace std;

int main()
{
    const string some_lines = "I have a dream. "
                              "You have a dream too.\n"
                              "We all have dreams.";

    istringstream input(some_lines);
    for (string word; input >> word;)
    {
        std::print("{} ", word);
    }
    std::println("");

    ostringstream output;
    output << std::format("1 + 1 = {}\n", 2);
    output << std::format("2 + 2 = {}\n", 4);
    std::println("{}", output.str());
}

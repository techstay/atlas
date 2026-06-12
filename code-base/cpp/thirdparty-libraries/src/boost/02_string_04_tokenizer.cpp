#include <boost/tokenizer.hpp>
#include <print>
#include <string>

int main()
{
    // char_separator
    std::string                                   csv = "apple,banana,,cherry,";
    boost::char_separator<char>                   sep(",");
    boost::tokenizer<boost::char_separator<char>> tok(csv, sep);
    std::print("char_separator: ");
    for (const auto& t : tok) { std::print("[{}] ", t); }
    std::println("");

    // escaped_list_separator (CSV with quotes)
    std::string                         quoted = R"(name,"value with, comma",simple)";
    boost::escaped_list_separator<char> els;
    boost::tokenizer<boost::escaped_list_separator<char>> qtok(quoted);
    std::print("escaped_list: ");
    for (const auto& t : qtok) { std::print("[{}] ", t); }
    std::println("");

    // custom separator (pipe)
    std::string                                   piped = "one|two|three|four";
    boost::char_separator<char>                   pipe_sep("|");
    boost::tokenizer<boost::char_separator<char>> ptok(piped, pipe_sep);
    std::print("pipe separator: ");
    for (const auto& t : ptok) { std::print("[{}] ", t); }
    std::println("");

    // keep empty tokens
    std::string                                   multi = "a::b:::c";
    boost::char_separator<char>                   dsep(":", "", boost::keep_empty_tokens);
    boost::tokenizer<boost::char_separator<char>> dtok(multi, dsep);
    std::print("keep_empty: ");
    for (const auto& t : dtok) { std::print("[{}] ", t); }
    std::println("");

    return 0;
}

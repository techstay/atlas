import std;

class FileError : public std::runtime_error
{
    std::string path_;

public:
    explicit FileError(const std::string& path)
        : std::runtime_error("failed to open: " + path), path_(path)
    {
    }

    const std::string& path() const noexcept { return path_; }
};

class ParseError : public std::logic_error
{
    int line_;

public:
    explicit ParseError(int line, const std::string& msg) : std::logic_error(msg), line_(line) {}

    int line() const noexcept { return line_; }
};

int main()
{
    try
    {
        throw FileError("/etc/config.yaml");
    }
    catch (const FileError& e)
    {
        std::println("caught FileError: file={}, error={}", e.path(), e.what());
    }

    try
    {
        throw ParseError(42, "unexpected token");
    }
    catch (const ParseError& e)
    {
        std::println("caught ParseError: line={}, error={}", e.line(), e.what());
    }
}

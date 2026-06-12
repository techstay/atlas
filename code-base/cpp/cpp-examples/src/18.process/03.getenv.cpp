import std;

int main()
{
    // std::getenv: retrieve environment variable value. Returns nullptr if not found.
    const char* path = std::getenv("PATH");
    std::println("PATH = {}", path ? path : "(not set)");

    const char* home = std::getenv("HOME");
    std::println("HOME = {}", home ? home : "(not set)");

    const char* nonexistent = std::getenv("THIS_VAR_DOES_NOT_EXIST");
    std::println("nonexistent = {}", nonexistent ? nonexistent : "(not set)");

    // Modifying the returned pointer is UB; copy it first.
    if (const char* lang = std::getenv("LANG"))
    {
        std::string lang_copy(lang);
        std::println("LANG (copied) = {}", lang_copy);
    }

    // std::setenv (POSIX, not standard C++) — available on Linux/macOS.
    // setenv("MY_VAR", "hello", 1);  // 1 = overwrite
    // std::println("MY_VAR = {}", std::getenv("MY_VAR"));
}

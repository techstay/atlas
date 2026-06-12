import std;

int main()
{
    // std::system: execute a shell command. Returns the exit status of the command.
    // On POSIX, the return value is a wait-status encoding (use WEXITSTATUS to extract exit code).
    // Returns -1 on failure to launch the shell.

    // ⚠️ SECURITY WARNING: std::system() passes the command string to the shell,
    // which is vulnerable to shell injection if any part of the command comes
    // from untrusted input. Prefer platform-specific APIs like CreateProcess
    // (Windows) or posix_spawn/exec* (POSIX) for production code.

    std::println("=== echo ===");
    int ret = std::system("echo hello from shell");
    std::println("exit status: {}", ret);

    std::println("\n=== date ===");
    ret = std::system("date");
    std::println("exit status: {}", ret);

    std::println("\n=== nonexistent command ===");
    ret = std::system("this_command_does_not_exist");
    std::println("exit status: {}", ret);

    // std::popen (POSIX, not standard C++) — open a pipe to/from a process.
    // FILE* pipe = std::popen("ls -la", "r");
    // if (pipe)
    // {
    //     char buf[256];
    //     while (fgets(buf, sizeof(buf), pipe))
    //         std::print("{}", buf);
    //     std::pclose(pipe);
    // }
}

// Signal constants (SIGINT, SIGTERM, SIG_DFL, SIG_IGN) are preprocessor
// macros defined in <csignal>. Like `assert`, they cannot be exported
// through C++ modules, so we #include the header alongside `import std`.
import std;
#include <csignal>

volatile std::sig_atomic_t g_signal_received = 0;

void signal_handler(int signum)
{
    g_signal_received = signum; // async-signal-safe: only assign to sig_atomic_t
}

int main()
{
    // std::signal: register a handler for a signal.
    std::signal(SIGINT, signal_handler);
    std::signal(SIGTERM, signal_handler);

    // std::raise: send a signal to the current process.
    std::println("main: raising SIGINT");
    g_signal_received = 0;
    std::raise(SIGINT);
    if (g_signal_received)
    {
        auto sig = g_signal_received; // copy to non-volatile for formatting
        std::println("signal_handler: caught signal {}", sig);
    }

    std::println("main: raising SIGTERM");
    g_signal_received = 0;
    std::raise(SIGTERM);
    if (g_signal_received)
    {
        auto sig = g_signal_received;
        std::println("signal_handler: caught signal {}", sig);
    }

    // SIG_DFL = default handler, SIG_IGN = ignore signal.
    std::signal(SIGINT, SIG_IGN);
    std::println("main: SIGINT is now ignored");
    std::raise(SIGINT);
    std::println("main: still alive after ignored SIGINT");

    // Restore default handler
    std::signal(SIGINT, SIG_DFL);
}

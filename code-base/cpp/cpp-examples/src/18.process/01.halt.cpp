import std;

void cleanup_1() { std::println("cleanup_1: first registered, runs last"); }
void cleanup_2() { std::println("cleanup_2: second registered, runs first"); }

void quick_cleanup() { std::println("quick_cleanup: registered via at_quick_exit"); }

int main()
{
    // std::atexit: register functions to be called on normal termination (std::exit or return from
    // main). Standard guarantees at least 32 registrations; exceeding is UB.
    std::atexit(cleanup_1);
    std::atexit(cleanup_2);
    std::at_quick_exit(quick_cleanup);

    // std::quick_exit(0) calls at_quick_exit-registered functions, then terminates without flushing
    // streams. The code after std::quick_exit() is never reached.
    std::println("main: about to call std::quick_exit(0)");
    std::quick_exit(0);

    // This line is dead code — std::exit already terminated the process.
    std::println("This will NOT be printed");
}

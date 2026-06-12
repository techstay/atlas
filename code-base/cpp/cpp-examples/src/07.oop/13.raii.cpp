import std;

// RAII: Resource Acquisition Is Initialization
// Acquire resource in constructor, release in destructor — exception-safe and automatic.
class Resource
{
    std::string name;

public:
    Resource(std::string_view n) : name(n) { std::println("[{}] Acquired", name); }

    ~Resource() { std::println("[{}] Released", name); }

    void use() { std::println("[{}] In use", name); }
};

void raii_scope_demo()
{
    Resource r1("file");
    Resource r2("socket");
    r1.use();
    r2.use();
    // r2 and r1 are automatically released in reverse order when scope exits
    std::println("--- leaving scope ---");
}

void raii_and_exception_demo()
{
    try
    {
        Resource r("transaction");
        r.use();
        throw std::runtime_error("something went wrong");
    }
    catch (const std::exception& e)
    {
        std::println("Caught: {}", e.what());
    }
    // Resource is STILL released even though an exception was thrown!
}

int main()
{
    // Standard library RAII examples:
    // - std::lock_guard   — locks mutex, auto-unlocks
    // - std::unique_ptr   — owns heap object, auto-deletes
    // - std::fstream      — opens file, auto-closes
    // - std::string       — owns buffer, auto-frees

    std::println("=== Scope demo ===");
    raii_scope_demo();

    std::println("\n=== Exception demo ===");
    raii_and_exception_demo();

    std::println("\nAll resources safely released.");
}

import std;

int main()
{
    // Catch by const reference to preserve polymorphic type (avoid slicing).
    try
    {
        throw std::out_of_range("index 10 out of range [0, 5)");
    }
    catch (const std::out_of_range& e)
    {
        std::println("catch out_of_range: {}", e.what());
    }
    catch (const std::logic_error& e)
    {
        std::println("catch logic_error: {}", e.what());
    }
    catch (...)
    {
        std::println("catch all");
    }

    // Catch ordering: most-derived first. std::runtime_error is NOT a
    // std::logic_error, so it falls through to catch(...).
    try
    {
        throw std::runtime_error("network timeout");
    }
    catch (const std::logic_error& e)
    {
        std::println("catch logic_error: {}", e.what());
    }
    catch (...)
    {
        std::println("catch all: {}", "runtime_error is not a logic_error");
    }
}

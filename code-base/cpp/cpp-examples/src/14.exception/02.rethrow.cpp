import std;

int main()
{
    try
    {
        try
        {
            throw std::runtime_error("original runtime_error");
        }
        catch (const std::exception& e)
        {
            std::println("inner catch std::exception: {}", e.what());
            throw; // Rethrow the current exception unchanged.
                   // Key point: the outer catch can still match
                   // std::runtime_error precisely, because throw;
                   // preserves the original polymorphic type (no slicing).
        }
    }
    catch (const std::runtime_error& e)
    {
        std::println("outer catch std::runtime_error: {}", e.what());
    }
}

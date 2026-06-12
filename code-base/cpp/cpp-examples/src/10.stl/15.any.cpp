import std;

int main()
{
    // std::any — type-erased value container
    std::any any_val;
    std::println("any_val.has_value(): {}", any_val.has_value());

    any_val = 42;
    std::println("any_val.type().name(): {}", any_val.type().name());
    std::println("any_val value: {}", std::any_cast<int>(any_val));

    any_val = std::string{"Hello World"};
    std::println("any_val type: {}", any_val.type().name());
    std::println("any_val value: {}", std::any_cast<std::string>(any_val));

    // Wrong type cast throws std::bad_any_cast
    try
    {
        std::any_cast<double>(any_val);
    }
    catch (const std::bad_any_cast& e)
    {
        std::println("bad_any_cast: {}", e.what());
    }

    any_val.reset();
    std::println("any_val after reset: {}", any_val.has_value());
}

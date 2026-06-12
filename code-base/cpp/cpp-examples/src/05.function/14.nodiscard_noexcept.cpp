import std;

[[nodiscard]] int compute(int a, int b) { return a + b; }

void may_throw() noexcept(false) { throw std::runtime_error("may throw"); }

int safe_add(int a, int b) noexcept { return a + b; }

int main()
{
    // [[nodiscard]] warns when the return value is discarded
    std::println("compute(2, 3) = {}", compute(2, 3));
    // compute(1, 2); // warning: ignoring return value

    std::println("safe_add(4, 5) = {}", safe_add(4, 5));

    try
    {
        may_throw();
    }
    catch (const std::exception& e)
    {
        std::println("caught: {}", e.what());
    }

    std::println("safe_add is noexcept: {}", noexcept(safe_add(1, 2)));
    std::println("may_throw is noexcept: {}", noexcept(may_throw()));
}

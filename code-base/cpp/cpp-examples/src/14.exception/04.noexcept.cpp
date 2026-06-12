import std;

void safe_work() noexcept { std::println("noexcept function"); }

void risky_work() { throw std::runtime_error("risky failure"); }

// Conditional noexcept: noexcept only when the expression is noexcept.
template <typename T> void nothrow_move(T& dst, T& src) noexcept(noexcept(dst = std::move(src)))
{ dst = std::move(src); }

int main()
{
    static_assert(noexcept(safe_work()), "");
    static_assert(!noexcept(risky_work()), "");

    std::println("safe_work noexcept: {}", noexcept(safe_work()));
    std::println("risky_work noexcept: {}", noexcept(risky_work()));

    safe_work();

    try
    {
        risky_work();
    }
    catch (const std::exception& e)
    {
        std::println("caught from non-noexcept function: {}", e.what());
    }

    // Uncommenting the line below would call std::terminate():
    // void oops() noexcept { throw 1; }
    // oops();
}

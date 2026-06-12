import std;

class Timer
{
private:
    using Clock  = std::chrono::steady_clock;
    using Second = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<Clock> m_beg{Clock::now()};

public:
    void reset() { m_beg = Clock::now(); }

    double elapsed() const
    { return std::chrono::duration_cast<Second>(Clock::now() - m_beg).count(); }
};

void measure_time(auto callback)
{
    Timer t{};
    t.reset();
    callback();
    std::println("time used: {}", t.elapsed());
}

int main()
{
    using namespace std::literals::chrono_literals;
    measure_time([]() { std::this_thread::sleep_for(550ms); });
}

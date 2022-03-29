#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

class Timer
{
  private:
    using Clock  = chrono::steady_clock;
    using Second = chrono::duration<double, ratio<1>>;

    chrono::time_point<Clock> m_beg{Clock::now()};

  public:
    void reset()
    {
        m_beg = Clock::now();
    }

    double elapsed() const
    {
        return chrono::duration_cast<Second>(Clock::now() - m_beg).count();
    }
};

void measure_time(auto callback)
{
    static Timer t{};
    t.reset();
    callback();
    cout << "time used: " << t.elapsed() << endl;
}

int main()
{
    measure_time([]() {
        this_thread::sleep_for(chrono::milliseconds(500));
    });
}

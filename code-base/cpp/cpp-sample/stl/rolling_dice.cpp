#include <print>
#include <random>
#include <unordered_map>

using namespace std;

int main()
{
    mt19937 mt{random_device{}()};
    uniform_int_distribution die6{1, 6};
    constexpr int N = 10'000'000;

    unordered_map<int, int> m;

    for (int i = 0; i < N; i++)
    {
        m[die6(mt)]++;
    }

    for (int i = 1; i <= 6; i++)
    {
        std::println("{}:{}", i, m[i]);
    }
}

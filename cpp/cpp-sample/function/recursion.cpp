#include <print>
#include <vector>

using namespace std;

int fibonacci1(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci1(n - 2) + fibonacci1(n - 1);
}

// fibonacci with memorization version
long fibonacci2(int n)
{
    static auto result = vector<long>{0, 1};
    if (n < result.size())
    {
        return result[n];
    }
    result.push_back(fibonacci2(n - 1) + fibonacci2(n - 2));
    return result[n];
}

int main()
{
    std::println("fib(5): {}", fibonacci1(5));
    std::println("fib(50): {}", fibonacci2(50));
}

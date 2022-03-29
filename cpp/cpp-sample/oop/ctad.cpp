#include <iostream>
#include <ostream>

using namespace std;

template <typename T, typename U>
class Pair
{

  public:
    T first{};
    U second{};
};

// class template arguments deduction, available in c++17
template <typename T, typename U>
Pair(T, U) -> Pair<T, U>;

template <typename T, typename U>
ostream &operator<<(ostream &out, const Pair<T, U> &pair)
{
    out << pair.first << ", " << pair.second;
    return out;
}

int main()
{
    auto pair1 = Pair{3, 4};
    auto pair2 = Pair<double, int>{3, 4};
}

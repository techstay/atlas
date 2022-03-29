#include <iostream>

using namespace std;

int main(int argc, const char **argv)
{
    int i = 1'000;
    double d{};

    // implicit cast
    d = i;
    cout << d << endl;

    // explicit cast
    d = static_cast<double>(i);
    cout << d << endl;

    return 0;
}
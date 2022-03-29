#include <iomanip>
#include <iostream>
#include <limits>

// available in c++20
int main()
{
    using namespace std;
    using namespace std::numbers;

    cout << setprecision(numeric_limits<long double>::digits10);
    cout << "pi:\t" << pi << endl;
    cout << "e:\t" << e << endl;
    cout << "ln2:\t" << ln2 << endl;
    cout << "ln10:\t" << ln10 << endl;
    cout << "sqrt2:\t" << sqrt2 << endl;
}

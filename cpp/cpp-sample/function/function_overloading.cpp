#include <iostream>

using namespace std;

int sum(int a, int b)
{
    cout << "int sum" << endl;
    return a + b;
}

double sum(double a, double b)
{
    cout << "double sum" << endl;
    return a + b;
}

int main()
{
    cout << sum(2, 3) << endl;
    cout << sum(3.0, 4.0) << endl;
    cout << sum(static_cast<double>(3), 100.0) << endl;
}

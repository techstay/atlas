#include <print>
#include <vector>

using namespace std;

int main()
{
    // empty vector
    vector<int> v1;
    // vector with 5 elements
    vector<int> v2(5);
    // vector initialization
    vector v3{1, 2, 3, 4, 5};

    // vector length
    println("the length of v3: {}", v3.size());

    // resizing
    v1.resize(10);
    println("the length of v1: {}", v1.size());
}

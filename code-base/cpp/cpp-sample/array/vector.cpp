#include <print>
#include <vector>

using namespace std;

int main()
{
    // Empty vector
    vector<int> v1;
    // Vector with 5 elements
    vector<int> v2(5);
    // Vector initialization
    vector v3{1, 2, 3, 4, 5};

    // Vector size
    println("The size of v3: {}", v3.size());

    // Resize the vector
    v1.resize(10);
    println("The size of v1: {}", v1.size());
}

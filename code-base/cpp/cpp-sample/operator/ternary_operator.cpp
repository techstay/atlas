#include <print>

using namespace std;

int main()
{
    int marks{80};
    string result = marks >= 60 ? "passed" : "failed";
    std::println("{}", result);
}

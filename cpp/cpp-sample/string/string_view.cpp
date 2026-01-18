#include <print>
#include <string_view>

using namespace std;

int main()
{
    // a string_view is read-only strings
    // which is more efficient than a string
    string_view str{"abcd"};

    std::println("{}", str);
}

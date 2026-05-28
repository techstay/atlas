#include <print>
#include <string_view>

using namespace std;

int main()
{
    // string_view provides read-only access without owning data
    // More efficient than std::string for read-only operations
    string_view str{"abcd"};

    std::println("{}", str);
}

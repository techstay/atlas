#include <bitset>
#include <print>

using namespace std;

int main()
{
    auto b1 = bitset<4>{0b0110};
    auto b2 = bitset<4>{0b1010};

    // 按位取反
    std::println("not:\t{}", (~b1).to_string());
    // 按位与
    std::println("and:\t{}", (b1 & b2).to_string());
    // 按位或
    std::println("or:\t{}", (b1 | b2).to_string());
    // 按位异或
    std::println("xor:\t{}", (b1 ^ b2).to_string());
    // 左移
    std::println("lshfit:\t{}", (b1 << 2).to_string());
    // 右移
    std::println("rshift:\t{}", (b1 >> 2).to_string());
}
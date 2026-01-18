#include <bitset>
#include <print>

using namespace std;

int main()
{
    auto b1 = bitset<4>{0b0110};
    auto b2 = bitset<4>{0b1010};

    // Bitwise NOT
    std::println("not:\t{}", (~b1).to_string());
    // Bitwise AND
    std::println("and:\t{}", (b1 & b2).to_string());
    // Bitwise OR
    std::println("or:\t{}", (b1 | b2).to_string());
    // Bitwise XOR
    std::println("xor:\t{}", (b1 ^ b2).to_string());
    // Left shift
    std::println("lshfit:\t{}", (b1 << 2).to_string());
    // Right shift
    std::println("rshift:\t{}", (b1 >> 2).to_string());
}
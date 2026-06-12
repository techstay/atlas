import std;

int main()
{
    std::bitset<4> b1{0b0110};
    std::bitset<4> b2{0b1010};
    std::println("b1 = {}", b1.to_string());
    std::println("b2 = {}", b2.to_string());

    // Bitwise NOT
    std::println("~b1        = {}", (~b1).to_string());
    // Bitwise AND
    std::println("b1 & b2    = {}", (b1 & b2).to_string());
    // Bitwise OR
    std::println("b1 | b2    = {}", (b1 | b2).to_string());
    // Bitwise XOR
    std::println("b1 ^ b2    = {}", (b1 ^ b2).to_string());
    // Left shift
    std::println("b1 << 2    = {}", (b1 << 2).to_string());
    // Right shift
    std::println("b1 >> 2    = {}", (b1 >> 2).to_string());
}

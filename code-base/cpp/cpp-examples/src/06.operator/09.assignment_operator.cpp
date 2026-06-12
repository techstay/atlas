import std;

int main()
{
    // Simple assignment
    int a = 10;
    std::println("a = 10  -> a = {}", a);

    // Compound assignment operators
    a += 5; // a = a + 5
    std::println("a += 5  -> a = {}", a);

    a -= 3; // a = a - 3
    std::println("a -= 3  -> a = {}", a);

    a *= 2; // a = a * 2
    std::println("a *= 2  -> a = {}", a);

    a /= 4; // a = a / 4
    std::println("a /= 4  -> a = {}", a);

    a %= 3; // a = a % 3
    std::println("a %= 3  -> a = {}", a);

    // Bitwise compound assignments
    int b = 0b1100;
    std::println("b = 0b{}", std::bitset<4>(b).to_string());

    b &= 0b1010; // b = b & 0b1010
    std::println("b &= 0b1010  -> b = 0b{}", std::bitset<4>(b).to_string());

    b |= 0b0011; // b = b | 0b0011
    std::println("b |= 0b0011  -> b = 0b{}", std::bitset<4>(b).to_string());

    b ^= 0b0110; // b = b ^ 0b0110
    std::println("b ^= 0b0110  -> b = 0b{}", std::bitset<4>(b).to_string());

    b <<= 1; // b = b << 1
    std::println("b <<= 1     -> b = 0b{}", std::bitset<4>(b).to_string());

    b >>= 1; // b = b >> 1
    std::println("b >>= 1     -> b = 0b{}", std::bitset<4>(b).to_string());
}

import std;

int main()
{
    // Construction: from integer and from binary string
    std::bitset<4> bs1(5);      // 5 = 0101
    std::bitset<4> bs2("1010"); // from string

    std::println("bs1 (from 5): {}", bs1.to_string());
    std::println("bs2 (from \"1010\"): {}", bs2.to_string());

    // Modification: set(), reset(), flip()
    bs1.set(1); // set bit 1 (0-based)
    std::println("bs1.set(1): {}", bs1.to_string());
    bs1.reset(2); // reset bit 2
    std::println("bs1.reset(2): {}", bs1.to_string());
    bs1.flip(); // flip all bits
    std::println("bs1.flip(): {}", bs1.to_string());

    // Query: test(), operator[], all(), any(), none()
    std::println("bs2.test(0): {}", bs2.test(0));
    std::println("bs2[1]: {}", static_cast<bool>(bs2[1]));
    std::println("bs2.all(): {}", bs2.all());
    std::println("bs2.any(): {}", bs2.any());
    std::println("bs2.none(): {}", bs2.none());

    // Count and size
    std::println("bs2.count(): {}", bs2.count());
    std::println("bs2.size(): {}", bs2.size());

    // Conversions
    std::println("bs2.to_string(): {}", bs2.to_string());
    std::println("bs2.to_ulong(): {}", bs2.to_ulong());
    std::println("bs2.to_ullong(): {}", bs2.to_ullong());

    // Bitwise operations
    std::bitset<4> bs3 = bs1 & bs2; // AND
    std::bitset<4> bs4 = bs1 | bs2; // OR
    std::bitset<4> bs5 = bs1 ^ bs2; // XOR
    std::bitset<4> bs6 = ~bs1;      // NOT
    std::bitset<4> bs7 = bs2 << 1;  // left shift
    std::bitset<4> bs8 = bs2 >> 1;  // right shift

    std::println("bs1 & bs2: {}", bs3.to_string());
    std::println("bs1 | bs2: {}", bs4.to_string());
    std::println("bs1 ^ bs2: {}", bs5.to_string());
    std::println("~bs1: {}", bs6.to_string());
    std::println("bs2 << 1: {}", bs7.to_string());
    std::println("bs2 >> 1: {}", bs8.to_string());
}

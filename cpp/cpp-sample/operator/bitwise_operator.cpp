#include <bitset>
#include <iostream>

using namespace std;

int main()
{
    auto b1 = bitset<4>{0b0110};
    auto b2 = bitset<4>{0b1010};

    // 按位取反
    cout << "not:\t" << ~b1 << endl;
    // 按位与
    cout << "and:\t" << (b1 & b2) << endl;
    // 按位或
    cout << "or:\t" << (b1 | b2) << endl;
    // 按位异或
    cout << "xor:\t" << (b1 ^ b2) << endl;
    // 左移
    cout << "lshfit:\t" << (b1 << 2) << endl;
    // 右移
    cout << "rshift:\t" << (b1 >> 2) << endl;
}
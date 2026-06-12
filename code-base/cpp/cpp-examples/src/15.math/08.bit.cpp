import std;

int main()
{
    using namespace std;
    unsigned x = 0b11010110;

    println("x            = 0b{:08b} = {}", x, x);
    println("popcount(x)  = {} (number of 1-bits)", popcount(x));
    println("countl_zero(x)= {} (leading zeros in 32-bit unsigned)", countl_zero(x));
    println("countl_one(x) = {} (leading ones)", countl_one(x));
    println("countr_zero(x)= {} (trailing zeros)", countr_zero(x));
    println("countr_one(x) = {} (trailing ones)", countr_one(x));
    println("bit_width(x) = {} (smallest n with 2^n > x)", bit_width(x));
    println("bit_ceil(70) = {}", bit_ceil(70u));
    println("bit_floor(70)= {}", bit_floor(70u));
    println("has_single_bit(64)  = {}", has_single_bit(64u));
    println("has_single_bit(70)  = {}", has_single_bit(70u));
    println("rotl(x, 3)   = 0b{:08b} = {}", rotl(x, 3), rotl(x, 3));
    println("byteswap(0x12345678) = 0x{:08x}", byteswap(0x12345678u));
}

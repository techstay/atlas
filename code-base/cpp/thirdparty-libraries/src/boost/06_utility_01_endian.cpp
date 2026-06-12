#include <boost/endian/arithmetic.hpp>
#include <boost/endian/conversion.hpp>
#include <cstdint>
#include <print>

int main()
{
    // native to big endian
    uint32_t val = 0x12345678;
    uint32_t big = boost::endian::native_to_big(val);
    std::println("native 0x{:08X} -> big 0x{:08X}", val, big);

    // native to little endian
    uint32_t little = boost::endian::native_to_little(val);
    std::println("native 0x{:08X} -> little 0x{:08X}", val, little);

    // endian reverse
    uint32_t reversed = boost::endian::endian_reverse(val);
    std::println("reverse 0x{:08X} -> 0x{:08X}", val, reversed);

    // big to native
    uint32_t back = boost::endian::big_to_native(big);
    std::println("big 0x{:08X} -> native 0x{:08X}", big, back);

    // conditionally reverse
    uint32_t x = 0xAABBCCDD;
    uint32_t y =
        boost::endian::conditional_reverse<boost::endian::order::native, boost::endian::order::big>(
            x);
    std::println("conditional_reverse: 0x{:08X} -> 0x{:08X}", x, y);

    // endian-aware type
    boost::endian::big_uint32_t big_val = 0xDEADBEEF;
    std::println("big_uint32_t: 0x{:08X}", static_cast<uint32_t>(big_val));

    return 0;
}

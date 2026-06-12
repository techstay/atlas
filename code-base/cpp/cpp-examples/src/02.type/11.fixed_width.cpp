import std;

int main()
{
    // Fixed-width integer types from <cstdint> (C++11).
    // Guaranteed exact bit width on every conforming platform.
    std::int8_t   i8   = 100;
    std::int16_t  i16  = 100;
    std::int32_t  i32  = 10'000;
    std::int64_t  i64  = 10'000'000;
    std::uint8_t  ui8  = 200;
    std::uint16_t ui16 = 2'000;
    std::uint32_t ui32 = 20'000;
    std::uint64_t ui64 = 20'000'000;

    // NOTE: most implementations alias int8_t/uint8_t to (un)signed char,
    // so std::println formats them as a CHARACTER by default.  Cast to
    // int first so you see the numeric value.
    std::println("int8:   {} ({} bits)", static_cast<int>(i8), sizeof(i8) * 8);
    std::println("int16:  {} ({} bits)", i16, sizeof(i16) * 8);
    std::println("int32:  {} ({} bits)", i32, sizeof(i32) * 8);
    std::println("int64:  {} ({} bits)", i64, sizeof(i64) * 8);
    std::println("uint8:  {} ({} bits)", static_cast<unsigned>(ui8), sizeof(ui8) * 8);
    std::println("uint16: {} ({} bits)", ui16, sizeof(ui16) * 8);
    std::println("uint32: {} ({} bits)", ui32, sizeof(ui32) * 8);
    std::println("uint64: {} ({} bits)", ui64, sizeof(ui64) * 8);
}

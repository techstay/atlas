import std;

int main()
{
    // Character types for different encodings
    char     c   = 'c';
    wchar_t  wc  = L'c';
    char8_t  c8  = u8'c';
    char16_t c16 = u'c';
    char32_t c32 = U'c';

    std::println("char:     '{}'", c);

    // `wchar_t` is platform-dependent: 16-bit (UTF-16 code unit) on Windows,
    // 32-bit (UTF-32) on most Unix platforms.  It does NOT portably hold a
    // Unicode code point.  For portable Unicode storage, prefer the C++20
    // char8_t / char16_t / char32_t types below.
    std::println("wchar_t:  U+{:04X} (sizeof = {} bytes)", static_cast<unsigned>(wc), sizeof(wc));

    // char8_t / char16_t / char32_t are guaranteed to hold one UTF-8/16/32
    // code unit respectively, regardless of platform.
    std::println("char8_t:  U+{:04X}", static_cast<unsigned>(c8));
    std::println("char16_t: U+{:04X}", static_cast<unsigned>(c16));
    std::println("char32_t: U+{:04X}", static_cast<unsigned>(c32));
}

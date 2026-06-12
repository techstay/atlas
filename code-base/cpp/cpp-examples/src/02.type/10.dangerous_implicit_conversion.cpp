import std;

int main()
{
    // 1. Signed/unsigned comparison: -1 is converted to a huge unsigned value
    {
        int          a{-1};
        unsigned int b{1};
        if (a < b) { std::println("-1 < 1 is true"); }
        else
        {
            // Print the unsigned-promoted bit pattern so the reader can see
            // why the comparison flipped: -1 reinterpreted as `unsigned` is
            // UINT_MAX, which is > 1.
            std::println("-1 < 1 is false: -1 reinterpreted as unsigned is {}",
                         static_cast<unsigned int>(a));
            std::println("UINT_MAX is {}", std::numeric_limits<unsigned int>::max());
        }
    }

    // 2. Float-to-int truncation: the fractional part is silently dropped
    {
        double d{3.9};
        int    i = d; // implicit, truncates
        std::println("double 3.9 -> int {}", i);
    }

    // 3. Pointer to bool: any non-null pointer is true
    {
        int  x{};
        int* p  = &x;
        bool b  = p; // implicit
        int* q  = nullptr;
        bool b2 = q; // implicit
        std::println("non-null pointer as bool: {}", b);
        std::println("nullptr as bool: {}", b2);
    }
}

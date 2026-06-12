import std;

#define YES
#define MY_NAME "techstay"
#define SQUARE(x) ((x) * (x))

int main()
{
    std::println("{}", MY_NAME);

    // Function-like macro
    std::println("SQUARE(5) = {}", SQUARE(5));

#ifdef YES
    std::println("You will see this line if YES is defined.");
#endif

#undef YES

#ifdef YES
    std::println("This line will NOT appear.");
#endif

// #if defined() supports logical combinations, unlike #ifdef
#define FEATURE_A
    // #define FEATURE_B

#if defined(FEATURE_A) && !defined(FEATURE_B)
    std::println("Feature A is on, Feature B is off.");
#endif
}

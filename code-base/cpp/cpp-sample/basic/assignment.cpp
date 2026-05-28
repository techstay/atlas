int main()
{
    // Copy initialization
    int a = 5;

    // Direct initialization
    int b(10);

    // List initialization, the preferred way
    int c{2};

    // Zero initialization
    // [[maybe_unused]] attribute is used to suppress warnings for unused variables
    [[maybe_unused]] int d{};
}
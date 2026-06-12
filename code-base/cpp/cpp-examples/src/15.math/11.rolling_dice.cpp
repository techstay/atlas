import std;

int main()
{
    // Use std::mt19937 (Mersenne Twister) for non-cryptographic random number generation
    // It provides a good balance between quality randomness and performance
    std::mt19937                  mt{std::random_device{}()};
    std::uniform_int_distribution die6{1, 6};
    constexpr int                 N = 10'000'000;

    std::unordered_map<int, int> m;

    for (int i = 0; i < N; i++) { m[die6(mt)]++; }

    for (int i = 1; i <= 6; i++)
    {
        double percentage = static_cast<double>(m[i]) / N * 100;
        std::println("{}: {} ({:.2f}%)", i, m[i], percentage);
    }
}

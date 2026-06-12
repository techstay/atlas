import std;

int main()
{
    using namespace std;
    mt19937 rng{random_device{}()};

    // Uniform integer [1, 6] - die roll
    uniform_int_distribution die{1, 6};
    print("d6 rolls: ");
    for (int i = 0; i < 5; ++i) { print("{} ", die(rng)); }
    println();

    // Uniform real [0.0, 1.0)
    uniform_real_distribution<double> u{0.0, 1.0};
    println("u01: {:.4f}", u(rng));

    // Normal (Gaussian) distribution - mean 0, std dev 1
    normal_distribution<double> gauss{0.0, 1.0};
    println("N(0,1): {:.4f}", gauss(rng));

    // Bernoulli distribution - p=0.3 (30% chance of Heads)
    bernoulli_distribution coin{0.3};
    println("coin(0.3): {}", coin(rng) ? "H" : "T");

    // Poisson distribution - lambda=4.0
    poisson_distribution<int> poisson{4.0};
    println("Poisson(4): {}", poisson(rng));

    // Exponential distribution - lambda=1.0
    exponential_distribution<double> exponential{1.0};
    println("Exponential(1): {:.4f}", exponential(rng));

    // Binomial distribution - n=10, p=0.5
    binomial_distribution<int> binomial{10, 0.5};
    println("Binomial(10, 0.5): {}", binomial(rng));

    // Shuffle example
    vector<int> vec{1, 2, 3, 4, 5};
    shuffle(vec.begin(), vec.end(), rng);
    print("Shuffled vector: ");
    for (int x : vec) { print("{} ", x); }
    println();

    // Sample example - sample 3 elements without replacement
    vector<int> population{10, 20, 30, 40, 50};
    vector<int> sample_result;
    sample(population.begin(), population.end(), back_inserter(sample_result), 3, rng);
    print("Sample of 3: ");
    for (int x : sample_result) { print("{} ", x); }
    println();

    // Re-seed for reproducibility
    rng.seed(42);
    println("Seeded mt19937: {}", rng());
}
import std;

int main()
{
    using namespace std;
    vector<double> data{2, 4, 4, 4, 5, 5, 7, 9};

    // mean = sum / n
    double m = accumulate(data.begin(), data.end(), 0.0) / static_cast<double>(data.size());

    // population variance = mean of (x_i - mean)^2 (divide by n, for entire population)
    double population_var = accumulate(data.begin(), data.end(), 0.0,
                                       [m](double a, double x) { return a + (x - m) * (x - m); }) /
                            data.size();

    // sample variance = average of (x_i - mean)^2 (divide by n-1, for sample from population)
    double sample_var = accumulate(data.begin(), data.end(), 0.0,
                                   [m](double a, double x) { return a + (x - m) * (x - m); }) /
                        (data.size() - 1);

    // median needs a sorted copy
    auto sorted = data;
    ranges::sort(sorted);
    auto   n   = sorted.size();
    double med = n % 2 ? sorted[n / 2] : (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0;

    // Print data using views::join_with for concise formatting
    println("data:   [{}]",
            data | views::transform([](auto x) { return format("{:>4}", static_cast<int>(x)); }) |
                views::join_with(", "sv));

    println("mean:   {}", m);
    println("median: {}", med);
    println("pop var: {:.3}", population_var);
    println("sam var: {:.3}", sample_var);
    println("pop std: {:.3}", sqrt(population_var));
    println("sam std: {:.3}", sqrt(sample_var));
}

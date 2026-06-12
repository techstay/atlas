#include <boost/bind/bind.hpp>
#include <boost/function.hpp>
#include <print>
#include <vector>

void print_sum(int a, int b) { std::println("{} + {} = {}", a, b, a + b); }
void print_val(int x) { std::println("value: {}", x); }

int main()
{
    // boost::function
    boost::function<void(int, int)> func = print_sum;
    func(3, 4);

    // bind with placeholders
    using namespace boost::placeholders;
    auto add5 = boost::bind(print_sum, _1, 5);
    add5(10);

    // bind with algorithms
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::for_each(v.begin(), v.end(), boost::bind(print_val, _1));

    // function as callback
    boost::function<int(int, int)> op;
    op = [](int a, int b) { return a * b; };
    std::println("6 * 7 = {}", op(6, 7));

    // function with member function
    struct Printer
    {
        void print(int x) const { std::println("Printer: {}", x); }
    };
    Printer                    p;
    boost::function<void(int)> pf = boost::bind(&Printer::print, &p, _1);
    pf(42);

    // function reset / empty check
    boost::function<void()> empty;
    std::println("empty: {}", empty.empty());
    empty = [] { std::println("now assigned"); };
    std::println("empty after assign: {}", empty.empty());
    empty();

    return 0;
}

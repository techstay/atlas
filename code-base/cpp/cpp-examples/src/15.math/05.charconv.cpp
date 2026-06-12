import std;

int main()
{
    using namespace std;
    char buf[64];

    // Number -> string
    auto [p1, _] = to_chars(begin(buf), end(buf), 12'345);
    *p1          = '\0';
    println("to_chars(int)        = '{}'", buf);

    auto [p2, _2] = to_chars(begin(buf), end(buf), 3.14159);
    *p2           = '\0';
    println("to_chars(double)     = '{}'", buf);

    auto [p3, _3] = to_chars(begin(buf), end(buf), 3.14159, chars_format::fixed, 2);
    *p3           = '\0';
    println("to_chars(prec=2)     = '{}'", buf);

    auto [p4, _4] = to_chars(begin(buf), end(buf), 255u, 16);
    *p4           = '\0';
    println("to_chars(hex)        = '{}'", buf);

    auto [p5, _5] = to_chars(begin(buf), end(buf), 12345.6789, chars_format::scientific, 3);
    *p5           = '\0';
    println("to_chars(scientific) = '{}'", buf);

    // String -> number
    int v;
    auto [p6, ec] = from_chars("2A", &"2A"[2], v, 16);
    if (ec == errc{}) { println("from_chars(\"2A\", base=16) = {} (consumed={})", v, (p6 - "2A")); }
    else
    {
        println("from_chars(\"2A\", base=16) failed: {}", make_error_code(ec).message());
    }

    double pi;
    auto [p7, ec2] = from_chars("3.14", &"3.14"[4], pi);
    if (ec2 == errc{}) { println("from_chars(\"3.14\")         = {}", pi); }
    else
    {
        println("from_chars(\"3.14\") failed: {}", make_error_code(ec2).message());
    }

    return 0;
}
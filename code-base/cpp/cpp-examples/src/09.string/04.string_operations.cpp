import std;

int main()
{
    std::string s = "Hello, C++ World!";

    // Query
    std::println("length: {}", s.length());
    std::println("empty:  {}", s.empty());

    // find — locate substring or character
    auto pos = s.find("C++");
    std::println("find 'C++' at: {}", pos);

    auto pos2 = s.find('o');
    std::println("find 'o' at:   {}", pos2);

    // rfind — search from the end
    auto pos3 = s.rfind('o');
    std::println("rfind 'o' at:  {}", pos3);

    // substr — extract substring
    std::println("substr(7, 3):  '{}'", s.substr(7, 3));

    // replace — replace portion of string
    std::string s2 = s;
    s2.replace(7, 3, "Modern C++");
    std::println("replace:        '{}'", s2);

    // starts_with / ends_with (C++20)
    std::println("starts_with 'Hello': {}", s.starts_with("Hello"));
    std::println("ends_with '!':       {}", s.ends_with('!'));

    // Conversion functions
    int    n  = 42;
    double pi = 3.14159;

    std::string sn     = std::to_string(n);
    std::string pi_str = std::to_string(pi);
    std::println("to_string: {} {}", sn, pi_str);

    int    n_back  = std::stoi("123");
    double pi_back = std::stod("3.14159");
    std::println("stoi/stod: {} {}", n_back, pi_back);

    // contains (C++23)
    std::println("contains 'C++': {}", s.contains("C++"));
    std::println("contains 'Rust': {}", s.contains("Rust"));
}

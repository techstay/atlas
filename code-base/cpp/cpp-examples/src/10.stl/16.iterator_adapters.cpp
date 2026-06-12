import std;

int main()
{
    // --- std::back_inserter: appends elements to the end of a container ---
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2;
    std::copy(v1.begin(), v1.end(), std::back_inserter(v2));
    std::print("v2 (after back_inserter copy): ");
    for (int x : v2) { std::print("{} ", x); }
    std::println("");

    std::fill_n(std::back_inserter(v2), 3, 4);
    std::print("v2 (after fill_n with back_inserter): ");
    for (int x : v2) { std::print("{} ", x); }
    std::println("");

    // --- std::front_inserter: prepends elements to the front (requires bidirectional iterator) ---
    std::list<int> l1 = {1, 2, 3};
    std::list<int> l2;
    std::copy(l1.begin(), l1.end(), std::front_inserter(l2));
    std::print("l2 (after front_inserter copy): ");
    for (int x : l2) { std::print("{} ", x); }
    std::println("");

    // --- std::inserter: inserts elements at a specific position ---
    std::vector<int> v3 = {1, 4, 5};
    auto             it = std::find(v3.begin(), v3.end(), 4);
    std::copy(v1.begin(), v1.end(), std::inserter(v3, it));
    std::print("v3 (after insert at position of 4): ");
    for (int x : v3) { std::print("{} ", x); }
    std::println("");

    // --- std::reverse_iterator: reverse iteration ---
    std::println("\nReverse iteration with rbegin/rend:");
    for (auto it = v3.rbegin(); it != v3.rend(); ++it) { std::print("{} ", *it); }
    std::println("");

    // Using make_reverse_iterator
    std::println("Reverse iteration with make_reverse_iterator:");
    for (auto it = std::make_reverse_iterator(v3.end());
         it != std::make_reverse_iterator(v3.begin()); ++it)
    {
        std::print("{} ", *it);
    }
    std::println("");

    // --- std::istream_iterator / std::ostream_iterator: stream iterators ---
    std::println("\nStream iterator demo (using stringstream):");
    std::stringstream          ss("10 20 30 40 50");
    std::istream_iterator<int> is_begin(ss);
    std::istream_iterator<int> is_end;
    std::vector<int>           v4(is_begin, is_end);
    std::print("Read from stringstream: ");
    for (int x : v4) { std::print("{} ", x); }
    std::println("");

    std::println("Write to cout: ");
    std::copy(v4.begin(), v4.end(), std::ostream_iterator<int>(std::cout, " "));
    std::println("");
}

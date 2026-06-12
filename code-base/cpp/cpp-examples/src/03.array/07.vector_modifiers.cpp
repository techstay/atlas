import std;

int main()
{
    std::vector<int> v{1, 2, 3};

    // push_back — copy/move-insert at the end
    v.push_back(4); // {1, 2, 3, 4}

    // emplace_back — construct in place, no temporary
    v.emplace_back(5); // {1, 2, 3, 4, 5}

    // insert — insert at an arbitrary position
    v.insert(v.begin() + 1, 99); // {1, 99, 2, 3, 4, 5}

    // pop_back — remove the last element
    v.pop_back(); // {1, 99, 2, 3, 4}

    // erase — remove by iterator
    v.erase(v.begin()); // {99, 2, 3, 4}

    for (int x : v) { std::print("{} ", x); }
    std::println();

    // clear — remove all elements
    v.clear();
    std::println("size after clear: {}", v.size());
}

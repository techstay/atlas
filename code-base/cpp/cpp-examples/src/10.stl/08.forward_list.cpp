import std;

int main()
{
    // std::forward_list - singly-linked list, lighter than std::list
    std::forward_list<int> fl{3, 4, 5};
    fl.push_front(2);
    auto fit = fl.before_begin(); // Iterator before first element
    fl.insert_after(fit, 1);      // Insert 1 at beginning
    std::println("forward_list:");
    for (int x : fl) { std::print("{} ", x); }
    std::println();
}

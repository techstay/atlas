import std;

int main()
{
    // std::priority_queue defaults to using std::vector as the underlying container
    // and std::less as the comparator (creating a max-heap)
    std::priority_queue<int> max_heap;
    for (int x : {3, 1, 4}) { max_heap.push(x); }
    std::println("max heap top: {}", max_heap.top());
    max_heap.pop();
    std::println("max heap next: {}", max_heap.top());

    // Min-heap with std::greater.
    // Template parameters:
    // - int: value type stored in the priority queue
    // - std::vector<int>: underlying container used to store the elements
    // - std::greater<int>: comparator used to determine the priority (min-heap)
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    for (int x : {3, 1, 4}) { min_heap.push(x); }
    std::println("min heap top: {}", min_heap.top());
    min_heap.pop();
    std::println("min heap next: {}", min_heap.top());

    // Lambda comparator for std::priority_queue
    auto cmp = [](int a, int b) { return a % 10 > b % 10; }; // priority by last digit ascending
    std::priority_queue<int, std::vector<int>, decltype(cmp)> custom_heap(cmp);
    for (int x : {15, 21, 34, 42}) { custom_heap.push(x); }
    std::println("custom heap top: {}", custom_heap.top());
}

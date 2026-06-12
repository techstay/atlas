#include <atomic>
#include <boost/lockfree/queue.hpp>
#include <print>
#include <thread>
#include <vector>

int main()
{
    std::println("=== boost::lockfree::queue examples ===");

    // 1. SPSC (Single Producer, Single Consumer) queue
    std::println("\n1. SPSC queue - producer/consumer:");
    boost::lockfree::queue<int> queue(128);
    std::atomic<bool>           done{false};

    // Producer thread
    std::thread producer(
        [&]
        {
            for (int i = 1; i <= 10; ++i)
            {
                while (!queue.push(i))
                {
                    // busy-wait if queue is full
                }
                std::println("  Produced: {}", i);
            }
            done = true;
        });

    // Consumer thread
    std::thread consumer(
        [&]
        {
            int val;
            while (!done || !queue.empty())
            {
                if (queue.pop(val)) { std::println("  Consumed: {}", val); }
            }
        });

    producer.join();
    consumer.join();

    // 2. Queue with fixed-size capacity
    std::println("\n2. Queue capacity behavior:");
    boost::lockfree::queue<int> cap_queue(4);

    std::println("  Pushing 5 items into capacity-4 queue:");
    for (int i = 1; i <= 5; ++i)
    {
        bool ok = cap_queue.push(i);
        std::println("  push({}) -> {}", i, ok ? "success" : "full");
    }

    std::println("  Draining:");
    int v;
    while (cap_queue.pop(v)) { std::println("  pop -> {}", v); }

    // 3. Multiple producers
    std::println("\n3. Multiple producers:");
    boost::lockfree::queue<int> mp_queue(256);
    std::atomic<int>            total_produced{0};

    auto producer_fn = [&](int id)
    {
        for (int i = 0; i < 5; ++i)
        {
            int val = id * 100 + i;
            while (!mp_queue.push(val)) {}
            total_produced.fetch_add(1);
        }
    };

    std::vector<std::thread> producers;
    for (int i = 0; i < 3; ++i) { producers.emplace_back(producer_fn, i); }

    for (auto& t : producers) { t.join(); }

    int val;
    int consumed = 0;
    while (mp_queue.pop(val))
    {
        std::println("  Got: {}", val);
        ++consumed;
    }
    std::println("  Total produced: {}, consumed: {}", total_produced.load(), consumed);

    std::println("\nAll lockfree examples completed!");
    return 0;
}

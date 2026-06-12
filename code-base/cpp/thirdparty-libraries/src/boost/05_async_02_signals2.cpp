#include <boost/signals2.hpp>
#include <print>
#include <string>

namespace sig = boost::signals2;

// A simple event emitter
struct Button
{
    sig::signal<void(const std::string&)> on_click;
    sig::signal<void(int, int)>           on_resize;

    void click(const std::string& user)
    {
        std::println("Button clicked by {}", user);
        on_click(user);
    }

    void resize(int w, int h) { on_resize(w, h); }
};

int main()
{
    std::println("=== boost::signals2 examples ===");

    Button btn;

    // 1. Connect multiple slots
    std::println("\n1. Multiple slots on one signal:");
    btn.on_click.connect([](const std::string& user)
                         { std::println("  [Logger] User '{}' clicked", user); });
    btn.on_click.connect([](const std::string& user)
                         { std::println("  [Analytics] Click event from '{}'", user); });

    btn.click("Alice");

    // 2. Connection management (disconnect)
    std::println("\n2. Disconnecting a slot:");
    auto conn = btn.on_click.connect([](const std::string& user)
                                     { std::println("  [Temp] This will only fire once"); });
    btn.click("Bob");
    conn.disconnect();
    std::println("  After disconnect:");
    btn.click("Bob");

    // 3. Scoped connection (auto-disconnect)
    std::println("\n3. Scoped connection:");
    {
        sig::scoped_connection scoped = btn.on_click.connect(
            [](const std::string& user) { std::println("  [Scoped] Active only in this scope"); });
        btn.click("Charlie");
    }
    std::println("  After scope exit:");
    btn.click("Charlie");

    // 4. Signal with return values (last-wins combiner)
    std::println("\n4. Signal with return values (last slot wins):");
    sig::signal<int(int, int)> adder;
    adder.connect([](int a, int b) { return a + b; });
    adder.connect([](int a, int b) { return a * b; });

    std::println("  3 + 4 = {} (last slot: 3 * 4)", *adder(3, 4));

    // 5. Multiple parameters
    std::println("\n5. Multi-parameter signal:");
    btn.on_resize.connect([](int w, int h) { std::println("  Window resized to {}x{}", w, h); });
    btn.resize(800, 600);

    // 6. Ordered handlers
    std::println("\n6. Ordered handlers:");
    sig::signal<void()> ordered;
    ordered.connect(1, [] { std::println("  second"); });
    ordered.connect(0, [] { std::println("  first"); });
    ordered();

    // 7. num_slots
    std::println("\n7. num_slots: {}", ordered.num_slots());

    std::println("\nAll signals2 examples completed!");
    return 0;
}

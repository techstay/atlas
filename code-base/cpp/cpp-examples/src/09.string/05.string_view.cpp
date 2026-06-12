import std;

int main()
{
    // string_view is a non-owning reference to a contiguous sequence of characters
    // It does NOT allocate or copy — just a pointer + size
    std::string_view sv{"Hello, string_view!"};
    std::println("sv:        '{}' (length={})", sv, sv.size());

    // Construct from std::string — zero-copy view
    std::string      str  = "owned string";
    std::string_view view = str;
    std::println("view:      '{}'", view);

    // Safe: "temp" is a string literal with static storage duration, not a temporary
    auto make_view = []() -> std::string_view { return "temp"; };
    std::println("temp view: '{}'", make_view());

    // ⚠️ Dangling: the temporary is destroyed after this statement
    // std::string_view bad = std::string{"dangling"};
    // std::println("{}", bad); // undefined behavior!

    // remove_prefix / remove_suffix — in-place slicing (no allocation)
    std::string_view path{"/home/user/file.txt"};
    path.remove_prefix(path.rfind('/') + 1); // keep filename only
    std::println("after remove_prefix: '{}'", path);
    path.remove_prefix(path.rfind('.')); // keep only extension
    std::println("after remove_suffix: '{}'", path);

    // substr returns a new string_view (still non-owning)
    std::string_view full{"Hello, World!"};
    std::string_view sub = full.substr(7, 5);
    std::println("substr: '{}'", sub);

    // You can mutate the underlying string through a view
    std::string      mutable_str = "Hello";
    std::string_view mut_view    = mutable_str;
    mutable_str[0]               = 'J';
    std::println("mutated: '{}'", mut_view); // "Jello"
}

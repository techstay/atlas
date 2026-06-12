import std;

void process(const std::string& lref) { std::println("lvalue ref: {}", lref); }

void process(std::string&& rref) { std::println("rvalue ref: {}", rref); }

int main()
{
    std::string a = "hello";

    process(a);            // a is an lvalue → binds to lvalue reference
    process("literal");    // "literal" is a const char[8] lvalue; implicit conversion
                           // creates a temporary std::string (prvalue) → rvalue ref overload
    process(std::move(a)); // std::move casts lvalue to rvalue → rvalue reference overload

    // After std::move, `a` is in a valid but unspecified state
    std::println("a after move: '{}'", a);
}

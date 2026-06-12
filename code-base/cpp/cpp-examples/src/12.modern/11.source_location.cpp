import std;

// C++20 std::source_location — captures file, line, function name at compile time
void log(std::string_view            message,
         const std::source_location& loc = std::source_location::current())
{ std::println("[{}:{}] {}: {}", loc.file_name(), loc.line(), loc.function_name(), message); }

void sub_function() { log("inside sub_function"); }

class MyClass
{
public:
    void method() { log("inside MyClass::method"); }
};

int main()
{
    log("in main");

    sub_function();

    MyClass obj;
    obj.method();

    // std::source_location is resolved at the CALL site because it is evaluated
    // as a default argument. While __FILE__ and __LINE__ can also expand at the
    // call site when used as default arguments, std::source_location provides a
    // clean, macro-free, type-safe API, and crucially allows capturing local
    // identifiers like function names (which __func__ / __FUNCTION__ cannot do
    // as default arguments because they are local variables).
    std::println("\nSource location captures where a function is called from,");
    std::println("providing a clean, macro-free alternative to __FILE__ / __LINE__ / __func__.");
}

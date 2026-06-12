import std;

int main()
{
    int    value = 42;
    double pi    = 3.14;

    void* data = &value; // void* can hold any object pointer type
    // *data;            // error: cannot dereference void* directly
    std::println("int = {}", *static_cast<int*>(data));

    data = &pi; // same pointer variable, different pointed-to type
    std::println("double = {}", *static_cast<double*>(data));
}

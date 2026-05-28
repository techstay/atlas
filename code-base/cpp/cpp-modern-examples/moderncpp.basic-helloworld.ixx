export module moderncpp.basic:helloworld;

import std;

using namespace std;

export namespace moderncpp
{

export void hello_world()
{
    println("Hello, welcome to the {} world!", "C++23");
}
} // namespace moderncpp

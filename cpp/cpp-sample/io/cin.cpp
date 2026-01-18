#include <iostream>
#include <print>
#include <string>
using namespace std;

int main()
{
    string name{};
    std::println("Please enter your name:");
    cin >> name;
    std::println("Your name is: {}", name);
}

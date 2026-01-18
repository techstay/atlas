#include <iostream>
#include <print>
#include <string>
using namespace std;

int main()
{
    string name{};
    std::println("请输入你的名字:");
    cin >> name;
    std::println("你的名字是:{}", name);
}

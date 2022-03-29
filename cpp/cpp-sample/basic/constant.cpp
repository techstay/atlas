#include <iostream>

using namespace std;

int main()
{
    int i        = 5;
    const int &r = i;
    i            = 10;
    // r            = 10; // r是常量，不可改变

    int j = 100;
    // const指针
    int *const cp = &i;
    // 可以通过指针修改对象的值
    *cp = 10;
    // 无法修改指针指向的对象
    // cp = &j;

    const int *p = &i;
    // 可以修改指针指向的对象
    p = &j;
    // 无法通过指针修改值
    // *p = 200;

    // 既是顶层const又是底层const
    const int *const ccp = &i;

    // 常量表达式
    constexpr int MAX_COUNT = 100;
    constexpr int MIN_COUNT = -MAX_COUNT;
    // i不是常量，所以下面的代码不能编译
    // constexpr int VARIABLE_COUNT = i;
}
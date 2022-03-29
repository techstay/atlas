#include <iostream>

using namespace std;

int main()
{
    int d1 = 5;
    int d2 = 6;

    // 定义两个指针
    int *p1, *p2;

    // 为指针赋值
    p1 = &d1;
    p2 = &d2;

    // 指针指向相应对象
    cout << "d1=" << d1 << ", *p1=" << *p1 << endl;

    // 修改指针指向的对象会直接改变它的值
    *p1 = 100;
    cout << "d1=" << d1 << ", *p1=" << *p1 << endl;

    // 清空指针
    p1 = p2 = nullptr;
}
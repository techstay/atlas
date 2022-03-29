#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 初始化向量
    vector<int> v1 = {1, 2, 3, 4}; // 初始化列表
    vector<int> v2(10, 1);         // 个数10，初始值1
    vector<int> v3{};              // 空向量

    // 动态添加数据
    for (int i = 0; i < 10; i++)
    {
        v3.push_back(i);
    }
}

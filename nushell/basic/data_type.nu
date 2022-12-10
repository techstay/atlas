# ------------------------------------------------------------------------------
# 数据类型
# ------------------------------------------------------------------------------

# 整数
64|describe
# 小数
12.3|describe
# 字符串
"88"|describe
# 布尔值
true|describe
# 转换
"1.6"|into decimal|describe
# 时间间隔
4wk|describe
# 区间
1..10|describe
1..<10|describe
# 文件大小
1gb|describe
# 二进制数据
0x[cafe]|describe
# 记录
{name:techstay, description:sadman}|describe
# 列表
[1,3,2,4]|describe
# 表
[[name, job]; [zhang3, teacher] [li4, doctor] [wang5, worker]] |describe
# 块
{echo 666}|describe

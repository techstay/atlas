let t1 = [[a b ]; [1 2]]

# 插入
$t1|insert c 3
# 更新
$t1|update b 20
# 插入或更新
$t1|upsert c 3
$t1|upsert b 20


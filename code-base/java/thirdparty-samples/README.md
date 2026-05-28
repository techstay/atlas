# thirdparty-samples

一些第三方类库的例子

## 特别说明

### 数据库

jdbc-sample 里用到了 mysql 数据库,需要通过 docker compose 启动,会自动加载 dump 数据,然后就可以在 gradle 测试中执行各种 jdbc 操作了.h2 内存数据库无需额外配置,在启动的时候通过测试命令注入数据.

需要启动数据库的时候,可以使用以下命令.导出的数据在 compose 配置文件中添加到了对应目录下,会在 mysql 启动的时候自动加载数据.

```sh
docker compose up -d

# 导出测试数据
docker exec jdbc-sample-db-1 sh -c 'exec mysqldump --databases test --routines -uroot -p"$MYSQL_ROOT_PASSWORD"' > testdb.sql
```

package yitian.study.other

import java.sql.DriverManager

@GrabResolver(name = 'aliyun', root = 'http://maven.aliyun.com/nexus/content/groups/public/')
@GrabConfig(systemClassLoader = true)
@Grapes(
        @Grab(group = 'mysql', module = 'mysql-connector-java', version = '5.1.40')
)
String url = 'jdbc:mysql://localhost:3306/test'
String username = 'root'
String password = '12345678'


def connection = DriverManager.getConnection(url, username, password)
assert connection != null

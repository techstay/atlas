package tech.techstay;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class JdbcUtil {


  public static Connection getH2Connection() throws SQLException {
    return DriverManager.getConnection(H2Info.url, H2Info.username, H2Info.password);
  }

  public static Connection getMySqlConnection() throws SQLException {
    return DriverManager.getConnection(MySqlInfo.url, MySqlInfo.username, MySqlInfo.password);

  }
}


// h2 database settings, specified but not used
class H2Info {
  static String driverName = "org.h2.Driver";
  static String url = "jdbc:h2:mem:myDb;DB_CLOSE_DELAY=-1";
  static String username = "sa";
  static String password = "sa";
}


class MySqlInfo {
  static String driverName = "com.mysql.cj.jdbc.Driver";
  static String url = "jdbc:mysql://localhost:3306/test";
  static String username = "root";
  static String password = "123456";
}

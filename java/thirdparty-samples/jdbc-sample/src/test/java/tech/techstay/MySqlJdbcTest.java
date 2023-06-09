package tech.techstay;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.*;

import javax.sql.RowSet;
import javax.sql.rowset.RowSetFactory;
import javax.sql.rowset.RowSetProvider;
import java.sql.*;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

public class MySqlJdbcTest {
  static Logger logger;
  static Connection connection;

  @BeforeAll
  static void init() throws SQLException {
    logger = LogManager.getLogger();
    connection = JdbcUtil.getMySqlConnection();
  }

  @AfterAll
  static void clean() throws SQLException {
    connection.close();
  }

  @BeforeEach
  void before() throws SQLException {

  }

  @AfterEach
  void after() throws SQLException {
    // deleting test data starting with test
    try (Statement stmt = connection.createStatement()) {
      stmt.executeUpdate("delete from user where username like 'test%'");
    }
  }

  @Test
  public void testConnection() {
    Assertions.assertThat(connection).isNotNull();
  }

  @Test
  public void testInsertionAndDeletion() throws SQLException {
    try (Statement statement = connection.createStatement()) {
      int lines =
        statement.executeUpdate("INSERT INTO user(username,password) VALUES('test1','123456')");
      Assertions.assertThat(lines).isEqualTo(1);
    }

    try (Statement stmt = connection.createStatement()) {
      int lines = stmt.executeUpdate("DELETE FROM user WHERE username='test1'");
      Assertions.assertThat(lines).isEqualTo(1);
    }
  }


  @Test
  public void testSelection() throws SQLException {
    List<User> users = new ArrayList<>();
    try (Statement statement = connection.createStatement()) {
      try (ResultSet rs = statement.executeQuery("SELECT *FROM user")) {

        while (rs.next()) {
          User user = new User(rs.getInt(1), rs.getString(2), rs.getString(3), rs.getString(4),
            rs.getObject(5, LocalDate.class));
          users.add(user);
        }
      }
    }
    Assertions.assertThat(users).hasSize(100);
    users.stream().limit(5).forEach(user -> logger.info(user.toString()));

  }

  @Test
  public void testPreparedInsertion() throws SQLException {
    try (PreparedStatement statement = connection.prepareStatement(
      "INSERT INTO user(username,password,nickname,birthday) VALUES(?,?,?,?)")) {
      statement.setString(1, "test");
      statement.setString(2, "12345678");
      statement.setString(3, "test");
      statement.setObject(4, LocalDate.of(1989, 4, 5));
      int rows = statement.executeUpdate();
      Assertions.assertThat(rows).isEqualTo(1);
    }


  }

  @Test
  public void testResultSetMetaData() throws SQLException {
    try (PreparedStatement statement = connection.prepareStatement("SELECT *FROM user limit 1")) {
      try (ResultSet rs = statement.executeQuery()) {
        ResultSetMetaData metaData = rs.getMetaData();
        int rows = 0;
        for (int i = 0; i < metaData.getColumnCount(); ++i) {
          logger.info(metaData.getColumnLabel(i + 1));
        }
        while (rs.next()) {
          for (int i = 0; i < metaData.getColumnCount(); ++i) {
            logger.info(rs.getString(i + 1));
          }
          rows++;
        }
        Assertions.assertThat(rows).isEqualTo(1);
      }
    }

  }

  @Test
  public void testDatabaseMetaData() throws SQLException {
    DatabaseMetaData metaData = connection.getMetaData();
    Assertions.assertThat(metaData).isNotNull();
    logger.info("DriverName: {}", metaData.getDriverName());
    logger.info("DriverVersion: {}", metaData.getDriverVersion());
    logger.info("DatabaseProductName: {}", metaData.getDatabaseProductName());
  }

  @Test
  public void testUpdatableResultSet() throws SQLException {
    try (Statement statement =
           connection.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_UPDATABLE)) {
      // inserting test data
      statement.executeUpdate("INSERT INTO user(username,password) VALUES('test3','112233')");
      String newPassword = "741741";

      // updating data from result set
      try (ResultSet rs = statement.executeQuery("SELECT *FROM user WHERE username='test3'")) {
        rs.absolute(1);
        rs.updateString("password", newPassword);
        rs.updateRow();
      }

      // verifying data is updated
      try (ResultSet rs = statement.executeQuery("SELECT *FROM user WHERE username='test3'")) {
        rs.absolute(1);
        Assertions.assertThat(rs.getString("password")).isEqualTo(newPassword);
      }

    }
  }

  @Test
  public void testJdbcRowSet() throws SQLException {
    RowSetFactory factory = RowSetProvider.newFactory();
    try (RowSet rs = factory.createJdbcRowSet()) {
      rs.setUrl(MySqlInfo.url);
      rs.setUsername(MySqlInfo.username);
      rs.setPassword(MySqlInfo.password);
      rs.setCommand("select count(*) from user");
      rs.execute();

      while (rs.next()) {
        Assertions.assertThat(rs.getInt(1)).isEqualTo(100);
      }
    }

  }

  @Test
  public void testInProcedure() throws SQLException {
    try (CallableStatement statement = connection.prepareCall("CALL find_all_blogs_of(?)")) {
      statement.setInt(1, 23);
      ResultSet rs = statement.executeQuery();

      List<Blog> blogs = new ArrayList<>();
      while (rs.next()) {
        Blog b = new Blog(rs.getInt(1), rs.getString(2), rs.getString(3),
          rs.getObject(4, LocalDateTime.class), rs.getInt(5));
        logger.info(b);
        blogs.add(b);
      }
      Assertions.assertThat(blogs).hasSizeGreaterThan(1);
    }
  }

  @Test
  public void testOutProcedure() throws SQLException {
    try (CallableStatement statement = connection.prepareCall("CALL get_total_user_count(?)")) {
      statement.registerOutParameter(1, Types.INTEGER);
      statement.execute();
      int count = statement.getInt(1);
      logger.info("用户个数是： {}", count);
      Assertions.assertThat(count).isEqualTo(100);
    }

  }

  @Test
  public void testTransaction() throws SQLException {
    // disabling auto commit for transaction tests
    connection.setAutoCommit(false);

    PreparedStatement selectOne =
      connection.prepareStatement("SELECT count(id) FROM user WHERE username =?");
    PreparedStatement insertOne =
      connection.prepareStatement("INSERT INTO user(username,password) VALUES(?,?)");
    // 成功插入
    String username1 = "testzhang3";
    insertOne.setString(1, username1);
    insertOne.setString(2, "123456");
    insertOne.executeUpdate();
    connection.commit();

    selectOne.setString(1, username1);
    ResultSet rs = selectOne.executeQuery();
    while (rs.next()) {
      Assertions.assertThat(rs.getInt(1)).isEqualTo(1);
    }

    // 插入失败
    String username2 = "testli4";
    insertOne.setString(1, username2);
    insertOne.setString(2, "123456");
    insertOne.executeUpdate();
    connection.rollback();

    selectOne.setString(1, username2);
    rs = selectOne.executeQuery();
    while (rs.next()) {
      Assertions.assertThat(rs.getInt(1)).isZero();
    }

    // rolling back auto commit settings
    connection.setAutoCommit(true);
  }
}

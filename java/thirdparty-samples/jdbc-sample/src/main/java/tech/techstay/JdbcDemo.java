package tech.techstay;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.stream.IntStream;

public class JdbcDemo {
  public static void main(String[] args) throws SQLException {


  }

  // these methods is used for initializing test data

  static void insertUsers() throws SQLException {
    Connection conn = JdbcUtil.getMySqlConnection();
    try (PreparedStatement stmt = conn.prepareStatement(
        "insert into user(username,password,nickname,birthday) values(?,?,?,?)")) {

      IntStream.rangeClosed(1, 100).forEach(i -> {
        User user = User.randomUser();
        try {
          stmt.setString(1, user.username());
          stmt.setString(2, user.password());
          stmt.setString(3, user.nickname());
          stmt.setObject(4, user.birthday());
          stmt.addBatch();
        } catch (SQLException e) {

          e.printStackTrace();
        }
      });

      stmt.executeBatch();

    }
  }

  static void insertBlog() throws SQLException {
    Connection conn = JdbcUtil.getMySqlConnection();
    try (PreparedStatement stmt = conn
        .prepareStatement("insert into blog(title,content,create_time,author) values(?,?,?,?)")) {

      IntStream.rangeClosed(1, 200).forEach(i -> {
        Blog blog = Blog.randomBlog();
        try {
          stmt.setString(1, blog.title());
          stmt.setString(2, blog.content());
          stmt.setObject(3, blog.createTime());
          stmt.setObject(4, blog.authorId() * 29 % 89);
          stmt.addBatch();
        } catch (SQLException e) {

          e.printStackTrace();
        }
      });

      stmt.executeBatch();

    }
  }
}

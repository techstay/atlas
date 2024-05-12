package tech.techstay.datetime;

import java.time.LocalDateTime;
import java.time.ZoneId;
import java.util.Date;

public class OldFashionedDate {
  public static void main(String[] args) {
    // 旧日期转换为新日期
    Date date = new Date();
    LocalDateTime dateTime = LocalDateTime.ofInstant(date.toInstant(), ZoneId.of("Asia/Shanghai"));
    System.out.println(dateTime);

    // 新日期转换为旧日期
    Date now = Date.from(LocalDateTime.now().atZone(ZoneId.systemDefault()).toInstant());
    System.out.println(now);
  }

}

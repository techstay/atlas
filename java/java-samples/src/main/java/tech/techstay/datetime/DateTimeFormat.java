package tech.techstay.datetime;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class DateTimeFormat {
  public static void main(String[] args) {
    LocalDateTime time = LocalDateTime.now();

    // default toString
    System.out.println(time);

    // formatting to strings
    DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
    System.out.println(time.format(formatter));

    // converted from strings
    time = LocalDateTime.from(formatter.parse("1993-11-25 12:00:15"));
    System.out.println(time);
  }

}

package tech.techstay.datetime;

import java.time.LocalDate;
import java.time.Period;

public class DatePeriod {
  public static void main(String[] args) {
    LocalDate birthday = LocalDate.of(1988, 4, 28);
    LocalDate today = LocalDate.now();
    Period period = birthday.until(today);
    System.out.println(period.getYears() + " years pass");
  }
}

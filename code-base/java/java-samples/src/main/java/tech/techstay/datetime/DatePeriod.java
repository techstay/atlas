package tech.techstay.datetime;

import java.time.LocalDate;
import java.time.Period;
import java.time.temporal.ChronoUnit;

public class DatePeriod {
  public static void main(String[] args) {
    LocalDate birthday = LocalDate.of(1988, 4, 28);
    LocalDate today = LocalDate.now();
    Period period = birthday.until(today);
    System.out.println("%d years %d months %d days passed".formatted(period.getYears(),
        period.getMonths(), period.getDays()));

    long days = ChronoUnit.DAYS.between(birthday, today);
    System.out.println("%d days passed".formatted(days));
  }
}

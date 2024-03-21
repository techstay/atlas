package tech.techstay.datetime;

import java.time.LocalDate;
import java.time.temporal.TemporalAdjusters;

public class DateDemo {
  public static void main(String[] args) {
    System.out.println("new date: ");

    LocalDate now = LocalDate.now();
    System.out.println(now);

    LocalDate thatDay = LocalDate.of(1988, 1, 16);
    System.out.println(thatDay);

    System.out.println("\ndate adjusters:");
    LocalDate theDayAfter10Days = thatDay.plusDays(10);
    System.out.println(theDayAfter10Days);

    LocalDate theDateBefore2Months = thatDay.minusMonths(2);
    System.out.println(theDateBefore2Months);

    LocalDate lastDayOfTheMonth = thatDay.with(TemporalAdjusters.lastDayOfMonth());
    System.out.println(lastDayOfTheMonth);

    LocalDate firstDayOfTheYear = thatDay.with(TemporalAdjusters.firstDayOfYear());
    System.out.println(firstDayOfTheYear);
  }
}

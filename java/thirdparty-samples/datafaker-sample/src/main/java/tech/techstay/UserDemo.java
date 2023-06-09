package tech.techstay;

import java.time.LocalDate;
import java.util.List;
import java.util.stream.IntStream;

public class UserDemo {
  public static void main(String[] args) {
    List<User> users = IntStream.rangeClosed(1, 20).mapToObj(i -> User.getRandomUser()).toList();
    users.stream().filter(e -> e.birthday().until(LocalDate.now()).getYears() <= 30)
        .forEach(System.out::println);
  }

}

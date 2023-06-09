package tech.techstay;


import net.datafaker.Faker;

import java.time.LocalDate;
import java.util.Random;

public record User(int id, String username, String password, String nickname, LocalDate birthday) {

  private static int idCounter = 0;
  private static Faker faker = new Faker(new Random(42));

  public static User randomUser() {
    return new User(idCounter++, faker.name().username().replace(".", "_"),
        faker.internet().password(), faker.name().firstName(),
        faker.date().birthday().toLocalDateTime().toLocalDate());
  }
}


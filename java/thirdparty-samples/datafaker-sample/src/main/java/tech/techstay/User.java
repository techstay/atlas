package tech.techstay;

import java.time.LocalDate;
import java.util.Random;
import net.datafaker.Faker;

public record User(int id, String name, String password, LocalDate birthday) {

  private static int idCounter = 0;
  private static Random random = new Random(42);
  private static Faker faker = new Faker(random);
  public static User getRandomUser() {
    return new User(idCounter++, faker.name().fullName(), faker.internet().password(),
        faker.date().birthday().toLocalDateTime().toLocalDate());
  }
}

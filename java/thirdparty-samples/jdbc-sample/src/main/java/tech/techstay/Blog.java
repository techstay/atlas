package tech.techstay;

import java.time.LocalDateTime;
import java.util.Random;
import java.util.concurrent.TimeUnit;
import net.datafaker.Faker;

public record Blog(int id, String title, String content, LocalDateTime createTime, int authorId) {

  private static int idCounter = 0;
  private static Random random = new Random(42);
  private static Faker faker = new Faker(random);
  public static Blog randomBlog() {
    return new Blog(idCounter++, faker.lorem().sentence(), faker.lorem().paragraph(),
        faker.date().past(365, 1, TimeUnit.DAYS).toLocalDateTime(), random.nextInt(10) + 1);
  }

}

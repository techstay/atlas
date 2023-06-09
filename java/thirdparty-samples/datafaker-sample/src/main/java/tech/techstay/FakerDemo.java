package tech.techstay;

import net.datafaker.Faker;

import java.util.List;
import java.util.Locale;
import java.util.Random;
import java.util.stream.Stream;

public class FakerDemo {
  public static void main(String[] args) {
    // set locale and seed

    Faker faker = new Faker(Locale.US, new Random(42));

    // fake data
    System.out.println(faker.name().fullName());
    System.out.println(faker.name().fullName());

    // using expressions to generate random strings
    System.out.println(faker.expression("#{bothify '?????##@gmail.com'}"));

    // different random data

    System.out.println("\nnames:");
    Stream<String> names = faker.stream(() -> faker.name().firstName()).nullRate(0).generate();
    System.out.println(names.limit(10).toList());

    System.out.println("\ncompanies:");
    List<String> companies = faker.collection(() -> faker.company().name()).nullRate(0).generate();
    System.out.println(companies.subList(0, 4));

    System.out.println("\ncats:");
    List<String> cats = faker.collection(() -> faker.cat().name()).nullRate(0).maxLen(7).generate();
    System.out.println(cats);

    System.out.println("\ncountries:");
    List<String> countries = faker.collection(() -> faker.country().name()).generate();
    System.out.println(countries);

    System.out.println("\naddresses:");
    List<String> addresses = faker.collection(() -> faker.address().fullAddress()).generate();
    System.out.println(addresses.subList(0, 3));

  }
}

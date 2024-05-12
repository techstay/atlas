package tech.techstay.function;

import java.util.Comparator;
import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class StreamOperation {
  public static void main(String[] args) {
    List<Person> people = generateRandomData();

    System.out.println("\noriginal list:");
    System.out.println(people);

    System.out.println("\nsorting:");
    // sorting by name
    System.out.println(
        people.stream().sorted(Comparator.comparing(Person::name)).collect(Collectors.toList()));

    System.out.println("\nfiltering:");
    System.out.println(people.stream().filter(e -> e.age() <= 18).collect(Collectors.toList()));

    System.out.println("\nmapping:");
    System.out.println(people.stream().map(Person::name).collect(Collectors.toList()));

    System.out.println("\nflat map:");
    System.out.println(Stream.of(Stream.of(1, 2, 3), Stream.of(4, 5, 6)).flatMap(e -> e).toList());

    System.out.println("\nreducing:");
    System.out.println(Stream.of(1, 2, 3, 4).reduce(0, (acc, e) -> acc + e));

    System.out.println("\naggregating:");
    System.out.println("sum of ages: " + people.stream().mapToInt(Person::age).sum());
    System.out.println(
        "average of ages: " + people.stream().mapToInt(Person::age).average().getAsDouble());
    System.out.println("max age: " + people.stream().mapToInt(Person::age).max().getAsInt());
    System.out.println("count: " + people.stream().count());

    System.out.println("\nforeach:");
    people.stream().limit(3).forEach(System.out::println);

    System.out.println("\nmatching:");
    System.out.println(people.stream().allMatch(e -> e.age() >= 18));
    System.out.println(people.stream().anyMatch(e -> e.age() >= 18));

    System.out.println("\nelements:");
    System.out.println(people.stream().limit(3).toList());
    System.out.println(people.stream().skip(7).toList());

    System.out.println("\ngrouping:");
    // grouping streams by length of names
    System.out.println(people.stream().collect(Collectors.groupingBy(e -> e.name().length())));
    // multiple grouping
    System.out.println(people.stream().collect(Collectors.groupingBy(e -> e.name().length(),
        Collectors.mapping(Person::name, Collectors.toList()))));

    System.out.println("\ncollecting:");
    System.out.println(people.stream().mapToInt(Person::age).boxed().collect(Collectors.toSet()));
    System.out.println(people.stream().mapToInt(Person::age).boxed().collect(Collectors.toList()));

    System.out.println("\ndistinct:");
    System.out.println(Stream.of(1, 1, 2, 3, 5, 5).distinct().toList());

    System.out.println("\njoining:");
    System.out.println(Stream.of(1, 2, 3, 4, 5).map(String::valueOf)
        .collect(Collectors.joining(": ", "[[", "]]")));

    System.out.println("\npartitioning:");
    System.out
        .println(Stream.of(1, 2, 3, 4, 5).collect(Collectors.partitioningBy(i -> i % 2 == 0)));

  }

  static List<Person> generateRandomData() {
    Random rand = new Random(42);
    String[] names = "jack lisa ada bob mike franklin john lin henry lion".split(" ");
    int[] ages = rand.ints(12, 32).limit(names.length).toArray();
    int[] ids = rand.ints(0, 10).limit(names.length).toArray();
    return IntStream.range(0, 10).mapToObj(i -> new Person(ids[i], names[i], ages[i]))
        .collect(Collectors.toList());
  }
}


record Person(int id, String name, int age) {

}

package tech.techstay.function;

import java.util.Random;
import java.util.stream.Stream;

public class StreamCreating {
  public static void main(String[] args) {

    Stream<Integer> stream1 = Stream.of(1, 2, 3, 4);

    Random rand = new Random();
    Stream<Integer> stream2 = Stream.generate(() -> rand.nextInt(100));

    Stream<Integer> stream3 = Stream.iterate(0, i -> i + 1);

    Stream.Builder<Integer> builder = Stream.builder();
    builder.add(1);
    builder.add(2);
    builder.add(3);

    Stream<Integer> stream4 = builder.build();

    System.out.println(stream3.limit(10).toList());
    System.out.println(stream4.toList());
  }

}

package tech.techstay.function;

import java.util.function.Function;

public class HighOrderFunction {


  public static void main(String[] args) {
    Function<String, String> foo;

    foo = String::toUpperCase;
    System.out.println(foo.apply("hello"));

    foo = e -> String.format("hello, %s", e);
    System.out.println(foo.apply("world"));

    measureTime(() -> {
      try {
        Thread.sleep(500);
      } catch (InterruptedException e1) {
        e1.printStackTrace();
      }
    });
  }

  static void measureTime(Runnable task) {
    long start = System.currentTimeMillis();
    task.run();
    long end = System.currentTimeMillis();
    System.out.format("Time used: %dms%n", end - start);

  }
}

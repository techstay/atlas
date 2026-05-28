package tech.techstay.function;

import java.util.stream.IntStream;

public class FunctionDemo {
  // java functions does not support default arguments
  static void foo(int a) {
    System.out.println("in foo: " + a);
  }

  // varargs
  // the varargs must be the rightmost argument
  static void bar(int... a) {
    System.out.print("in bar: ");
    for (int i : a) {
      System.out.print(i + " ");
    }
    System.out.println();
  }

  static void baz(int[] a) {
    System.out.print("in baz: ");
    for (int i : a) {
      System.out.print(i + " ");
    }
    System.out.println();
  }

  // recursive functions
  static int fibonacci(int n) {
    if (n == 0 || n == 1) {
      return n;
    } else {
      return fibonacci(n - 1) + fibonacci(n - 2);
    }
  }

  public static void main(String[] args) {
    foo(1);
    bar(1);
    bar(1, 2, 3);
    baz(new int[] {1});
    baz(new int[] {1, 2, 3, 4});

    IntStream.rangeClosed(1, 10).forEach(e -> System.out.print(fibonacci(e) + " "));
    System.out.println();
  }
}

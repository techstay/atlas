package tech.techstay.basic;

import java.util.stream.IntStream;

public class BreakAndContinue {
  public static void main(String[] args) {
    int[] intArray = IntStream.rangeClosed(1, 10).toArray();
    // break
    for (int i : intArray) {
      if (i == 5) {
        break;
      }
      System.out.print(i + " ");
    }
    System.out.println();

    // continue
    for (int i : intArray) {
      if (i == 5) {
        continue;
      }
      System.out.print(i + " ");
    }
    System.out.println();
  }
}

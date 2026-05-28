package tech.techstay.basic;

import java.util.List;
import java.util.stream.IntStream;

public class For {
  public static void main(String[] args) {
    List<Integer> list = IntStream.rangeClosed(1, 10).boxed().toList();
    for (int i = 0; i < list.size(); i++) {
      System.out.print(list.get(i) + " ");
    }
    System.out.println();

    // foreach
    for (Integer i : list) {
      System.out.print(i + " ");
    }
    System.out.println();
  }
}

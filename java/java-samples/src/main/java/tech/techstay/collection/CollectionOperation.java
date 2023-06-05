package tech.techstay.collection;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class CollectionOperation {
  public static void main(String[] args) {
    Random rand = new Random(42);

    List<Integer> integers = new ArrayList<>();
    integers.addAll(rand.ints(0, 10).boxed().toList());
    System.out.println(integers);

    System.out.println("adding:");
    integers.add(1);
    integers.addAll(List.of(1, 2, 3));
    System.out.println(integers);

    System.out.println("removing:");
    integers.remove(1);
    integers.removeIf(e -> e == 2);
    System.out.println(integers);

    System.out.println("containing:");
    boolean ifContains = integers.contains(1);
    System.out.println(ifContains);
    ifContains = integers.containsAll(List.of(1, 2, 3));
    System.out.println(ifContains);

    System.out.println("sorting:");
    Collections.sort(integers);
    System.out.println(integers);
    Collections.sort(integers, Collections.reverseOrder());
    System.out.println(integers);

    System.out.println("shuffling:");
    Collections.shuffle(integers);
    System.out.println(integers);

    System.out.println("reversing:");
    Collections.reverse(integers);
    System.out.println(integers);

    System.out.println("frequency:");
    System.out.println(Collections.frequency(integers, 1));

    System.out.println("retainAll:");
    integers.retainAll(List.of(1, 2, 3));
    System.out.println(integers);
  }
}

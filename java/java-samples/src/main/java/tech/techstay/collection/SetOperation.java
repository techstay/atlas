package tech.techstay.collection;

import java.util.*;
import java.util.stream.IntStream;

public class SetOperation {
  public static void main(String[] args) {
    // hash sets
    HashSet<Integer> set1 = new HashSet<>();
    // retaining the inserting order
    LinkedHashSet<Integer> set2 = new LinkedHashSet<>();
    // sorted sets
    TreeSet<Integer> set3 = new TreeSet<>();

    Random rand = new Random(42);
    List<Integer> unsortedList =
        IntStream.generate(() -> rand.nextInt(10)).limit(10).boxed().toList();

    set1.addAll(unsortedList);
    set2.addAll(unsortedList);
    set3.addAll(unsortedList);

    System.out.println(set1);
    System.out.println(set2);
    System.out.println(set3);

    System.out.println("set operations:");
    Set<Integer> other = Set.of(1, 2, 3, 4, 5);

    // union
    HashSet<Integer> union = new HashSet<>(set1);
    union.addAll(other);
    System.out.println(union);

    // intersect
    HashSet<Integer> intersect = new HashSet<>(set1);
    intersect.retainAll(other);
    System.out.println(intersect);

    // difference
    HashSet<Integer> difference = new HashSet<>(set1);
    difference.removeAll(other);
    System.out.println(difference);
  }
}

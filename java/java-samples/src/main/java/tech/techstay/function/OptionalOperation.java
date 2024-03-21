package tech.techstay.function;

import java.util.Optional;

public class OptionalOperation {
  @SuppressWarnings("unused")
  public static void main(String[] args) {
    Optional<Integer> obj1 = Optional.empty();
    Optional<Integer> obj2 = Optional.of(42);
    Optional<Integer> obj3 = Optional.ofNullable(null);

    if (obj1.isPresent()) {
      System.out.println(obj1.get());
    }
    obj1.ifPresent(System.out::println);

    int n = obj1.orElse(6);
    System.out.println(n);

    n = obj1.orElseGet(() -> 14);
    System.out.println(n);

  }
}

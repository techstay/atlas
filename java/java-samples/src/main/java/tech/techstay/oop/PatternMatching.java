package tech.techstay.oop;

public class PatternMatching {

  public static void main(String[] args) {
    // instanceof pattern matching
    Object obj = "abcd";
    if (obj instanceof Integer i) {
      System.out.println(i);
    } else if (obj instanceof String s) {
      System.out.println(s.toUpperCase());
    }

    // switch pattern matching
    // TODO: this is a preview feature
    // switch (obj) {
    // case Integer i -> System.out.println(i);
    // case String s -> System.out.println(s.toUpperCase());
    // default -> System.out.println("not matched");
    // }
  }
}

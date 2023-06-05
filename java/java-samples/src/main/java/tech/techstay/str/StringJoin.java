package tech.techstay.str;

import java.util.StringJoiner;

public class StringJoin {

  public static void main(String[] args) {
    // String.join
    System.out.println(String.join(", ", "abc", "xyz"));

    // StringJoiner
    StringJoiner joiner = new StringJoiner(", ", "[", "]");

    joiner.add("abc");
    joiner.add("xyz");

    System.out.println(joiner);
  }
}

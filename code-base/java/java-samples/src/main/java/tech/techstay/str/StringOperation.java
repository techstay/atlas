package tech.techstay.str;

import java.util.Arrays;

public class StringOperation {
  public static void main(String[] args) {

    String text = "abc defg xyz abc xyz";

    System.out.println("transforming:");
    System.out.println(text.toUpperCase());
    System.out.println(text.repeat(2));

    System.out.println("\nsubstring:");
    System.out.println(text.substring(0, 4));

    System.out.println("\nfinding and replacing:");
    System.out.println(text.indexOf("xyz"));
    System.out.println(text.indexOf("aaaaaaa"));
    System.out.println(text.lastIndexOf("a"));

    System.out.println(text.replaceFirst("a", "b"));
    System.out.println(text.replace("a", "b"));
    // replaceAll method accepts a regex
    System.out.println(text.replaceAll("\\b\\w{3}\\b", "fxxk"));

    System.out.println("\nsplitting:");
    System.out.println(Arrays.toString(text.split(" ")));
    System.out.println(Arrays.toString(text.split("a")));
  }

}

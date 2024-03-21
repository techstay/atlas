package tech.techstay.str;

import java.text.MessageFormat;

public class StringFormat {
  public static void main(String[] args) {
    String name = "John";
    int age = 30;
    var msg = String.format("My name is %s and I am %d years old.", name, age);
    var greeting = "Hello, I'm %s and I am %d years old.".formatted(name, age);

    System.out.println(msg);
    System.out.println(greeting);

    System.out.println("Format: %10s|%-10s|%5f|%.3f".formatted("Hello", "World", 3.1415, 3.1415));

    System.out.println(MessageFormat.format("Hello, I''m {0} and I am {1} years old.", name, age));
  }
}

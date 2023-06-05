package tech.techstay.basic;

import java.util.Random;

public class Switch {
  public static void main(String[] args) {
    Random random = new Random();
    int score = random.nextInt(0, 100);
    System.out.println("your score is " + score);

    switch (score / 10) {
      case 6:
        System.out.println("passed");
        break;
      case 7:
        System.out.println("good");
        break;
      case 8:
      case 9:
        System.out.println("very good");
        break;
      case 10:
        System.out.println("perfect");
        break;
      default:
        System.out.println("failed");
    }

    // using pattern matching
    String result = switch (score / 10) {
      case 6 -> "passed";
      case 7, 8, 9 -> "very good";
      case 10 -> "perfect";
      default -> "failed";
    };
    System.out.println(result);
  }
}

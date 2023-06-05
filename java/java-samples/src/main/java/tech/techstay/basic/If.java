package tech.techstay.basic;

import java.util.Random;

public class If {
  public static void main(String[] args) {
    Random random = new Random();
    int integer = random.nextInt(5, 15);
    if (integer < 10) {
      System.out.println("the integer is less than 10");
    } else if (integer > 11) {
      System.out.println("the integer is greater than 10");
    } else {
      System.out.println("the integer is 10");
    }
  }
}

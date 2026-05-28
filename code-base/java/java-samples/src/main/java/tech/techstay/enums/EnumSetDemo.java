package tech.techstay.enums;

import java.util.EnumSet;

enum Fruit {
  APPLE, BANANA, WATERMELON, PEAR
}


public class EnumSetDemo {
  public static void main(String[] args) {
    EnumSet<Fruit> fruit = EnumSet.noneOf(Fruit.class);

    fruit.add(Fruit.APPLE);
    fruit.add(Fruit.WATERMELON);
    fruit.add(Fruit.BANANA);
    System.out.println(fruit);

    System.out.println(fruit.contains(Fruit.WATERMELON));
    System.out.println(fruit.contains(Fruit.PEAR));
  }
}

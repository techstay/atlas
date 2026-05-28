package tech.techstay.oop;

import java.time.LocalDateTime;

public class Clazz {
  public static void main(String[] args) {
    new MyClazz();
    new MyClazz();
    MyClazz c = new MyClazz();
    c.hello();
    System.out.format("Class count: %d%n", MyClazz.getClazzCount());
  }
}


// declaring a class
class MyClazz {
  // static fields
  private static int count = 0;

  // static initializing blocks
  static {
    System.out.println("static initializing...");
  }

  // member fields
  private LocalDateTime localDateTime = LocalDateTime.now();

  // constructors
  MyClazz() {
    System.out.println("instantiating class: " + localDateTime);
    count++;
  }

  // static functions
  public static int getClazzCount() {
    return count;
  }

  // member methods
  public void hello() {
    System.out.println("hello from MyClazz at " + localDateTime);
  }
}

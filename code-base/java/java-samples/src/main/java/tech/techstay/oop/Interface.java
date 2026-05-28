package tech.techstay.oop;

interface MyInterface {
  // static methods
  static void baz() {
    System.out.println("baz");
  }

  // abstract methods
  void foo();

  // default methods
  default void bar() {
    System.out.println("bar");
  }
}


public class Interface {
  public static void main(String[] args) {
    MyInterface my = new MyClass();
    my.foo();
    my.bar();
    MyInterface.baz();
  }
}


class MyClass implements MyInterface {
  @Override
  public void foo() {
    System.out.println("foo");
  }
}

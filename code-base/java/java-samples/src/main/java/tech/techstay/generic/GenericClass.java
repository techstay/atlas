package tech.techstay.generic;

public class GenericClass {
  public static void main(String[] args) {
    MyValue<Integer> v1 = new MyValue<>(42);
    System.out.println(v1.getValue());

    MyValue<Double> v2 = new MyValue<>(3.14);
    System.out.println(v2.getValue());

  }
}


class MyValue<T> {
  private final T value;

  MyValue(T v) {
    value = v;
  }

  T getValue() {
    return value;
  }
}

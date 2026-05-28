package tech.techstay.basic;

public class Literal {
  @SuppressWarnings("unused")
  public static void main(String[] args) {
    // integers
    int i = 42;
    long li = 42000L;

    // floats
    float f = 3.14f;
    double d = 3.14;
    double expFloat = 3.14e-10;

    int octal = 012345;
    int hexadecimal = 0xcafe;
    int binary = 0b10101100;

    // you can get binary strings from integers
    System.out.println(Integer.toBinaryString(i));
    System.out.println(Integer.toBinaryString(binary));
  }
}

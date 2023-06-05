package tech.techstay.basic;

import java.util.Formatter;

public class Operator {
  public static void main(String[] args) {
    try (Formatter fmt = new Formatter(System.out)) {
      // arithmetic operators
      // +-*/%
      fmt.format("6 / 4 = %d%n", 6 / 4);
      fmt.format("6 %% 4 = %d%n", 6 % 4);

      // increment operators
      // ++ --
      int i = 4;
      fmt.format("i++: %d%n", i++);
      fmt.format("++i: %d%n", ++i);
      fmt.format("i--: %d%n", i--);
      fmt.format("--i: %d%n", --i);

      // relational operators
      // < > <= >= == !=
      fmt.format("6 > 4: %b%n", 6 > 4);
      fmt.format("6 == 4: %b%n", 6 == 4);

      // logical operators
      // && || !
      fmt.format("true and false: %b%n", true && false);
      fmt.format("true or false: %b%n", true || false);
      fmt.format("not true: %b%n", !true);

      // bitwise operators
      // >> << >>>(unsigned right shift)
      int n = 11;
      fmt.format("n is %s%n", Integer.toBinaryString(n));
      fmt.format("n >> 2: %s%n", Integer.toBinaryString(n >> 2));
      fmt.format("n << 2: %s%n", Integer.toBinaryString(n << 2));
      fmt.format("n >>> 2: %s%n", Integer.toBinaryString(n >>> 2));

      // ternary operator
      boolean condition = true;
      String result = condition ? "true" : "false";
      fmt.format("the result is %s%n", result);
    }
  }
}

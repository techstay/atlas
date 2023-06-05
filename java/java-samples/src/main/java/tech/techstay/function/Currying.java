package tech.techstay.function;

import java.util.function.BiFunction;
import java.util.function.Function;

public class Currying {
  public static void main(String[] args) {
    // currying means transforming a function that takes multiple arguments
    // into a function that takes a single argument.

    // uncurried functions
    BiFunction<Double, Double, Double> uncurriedSum = (a, b) -> a + b;

    // curried functions
    Function<Double, Function<Double, Double>> curriedSum = a -> b -> a + b;


    System.out.println("sum is " + uncurriedSum.apply(3.0, 5.0));
    System.out.println("sum is " + curriedSum.apply(6.0).apply(4.0));
  }
}

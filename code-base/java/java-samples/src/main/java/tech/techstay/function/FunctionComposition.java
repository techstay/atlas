package tech.techstay.function;

import java.util.function.Function;

public class FunctionComposition {
  public static void main(String[] args) {
    Function<Double, Double> square = e -> e * e, times2 = e -> e * 2,
        // square -> times2
        squareAndThenTimes2 = square.andThen(times2),
        // times2 -> square
        squareComposeTimes2 = square.compose(times2);

    System.out.println(squareAndThenTimes2.apply(3.0));
    System.out.println(squareComposeTimes2.apply(3.0));
  }
}

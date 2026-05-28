package tech.techstay.reflect;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;
import java.lang.reflect.InvocationTargetException;
import java.util.Arrays;

// custom annotation
// this annotation is used for test suites
@Target(ElementType.METHOD)
@Retention(RetentionPolicy.RUNTIME)
@interface MyTest {
  int[] values();

  String description() default "default description";
}


public class AnnotationDemo {
  public static void main(String[] args) {
    Class<MyTestSuite> testSuiteClass = MyTestSuite.class;

    Arrays.stream(testSuiteClass.getDeclaredMethods())
        .filter(m -> m.isAnnotationPresent(MyTest.class)).forEach(m -> {

          MyTest annotation = m.getAnnotation(MyTest.class);
          int[] values = annotation.values();

          System.out.format("%s: %s%n", annotation.description(), Arrays.toString(values));

          int sum;
          try {
            sum = (int) m.invoke(null, values);
            System.out.println(sum);

          } catch (IllegalAccessException | InvocationTargetException e) {
            e.printStackTrace();
          }
        });

  }
}


class MyTestSuite {
  @MyTest(values = {1, 2, 3, 4}, description = "returning sum of given arguments")
  public static int sum(int... values) {
    return Arrays.stream(values).sum();
  }

  @MyTest(values = {5, 2, 2, 5}, description = "returning multiplication of arguments")
  public static int multiply(int... values) {
    return Arrays.stream(values).reduce(1, (a, b) -> a * b);
  }
}

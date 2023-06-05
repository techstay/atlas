package tech.techstay.reflect;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.util.Arrays;

public class ReflectionDemo {
  public static void main(String[] args)
      throws NoSuchMethodException, SecurityException, InstantiationException,
      IllegalAccessException, IllegalArgumentException, InvocationTargetException {
    Class<Foo> clazz = Foo.class;

    System.out.println("listing constructors:");
    Constructor<?>[] cons = clazz.getConstructors();
    for (Constructor<?> c : cons) {
      System.out.println(c);
    }

    System.out.println("\nlisting methods:");
    Method[] methods = clazz.getMethods();
    for (Method m : methods) {
      System.out.println(m);
    }

    System.out.println("\nlisting declared methods:");
    Method[] declaredMethods = clazz.getDeclaredMethods();
    for (Method m : declaredMethods) {
      System.out.println(m);
    }

    System.out.println("\nlisting public methods:");
    Arrays.stream(declaredMethods).filter(m -> Modifier.isPublic(m.getModifiers()))
        .forEach(System.out::println);

    System.out.println("\ninstantiating objects:");
    Constructor<Foo> ctor = clazz.getConstructor(String.class);
    Foo obj = ctor.newInstance("my object");
    obj.foo();
    clazz.getDeclaredMethod("bar").invoke(obj);
    clazz.getDeclaredMethod("baz").invoke(null);
  }

}


class Foo {
  private final String value;

  public Foo(String v) {
    value = v;
  }

  static void baz() {
    System.out.println("baz");
  }

  public void foo() {
    System.out.println("foo " + value);
  }

  void bar() {
    System.out.println("bar " + value);
  }
}

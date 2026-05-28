package tech.techstay.reflect;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.util.Optional;

public class Clazz {
  public static void main(String[] args)
      throws NoSuchMethodException, SecurityException, InstantiationException,
      IllegalAccessException, IllegalArgumentException, InvocationTargetException {
    Optional<Class> clazz = Optional.empty();

    try {
      clazz = Optional.of(Class.forName("tech.techstay.reflect.MyClazz"));
    } catch (ClassNotFoundException e) {
      e.printStackTrace();
    }

    if (clazz.isPresent()) {
      Class c = clazz.get();
      System.out.println(c.getCanonicalName());

      if (c == MyClazz.class) {
        Class<MyClazz> genericClass = c;
        Constructor<MyClazz> con = genericClass.getConstructor();
        MyClazz obj = con.newInstance();
        obj.hello();
      }
    }
  }

}


class MyClazz {
  static {
    System.out.println("loading MyClazz");
  }

  public MyClazz() {}

  public void hello() {
    System.out.println("Hello from MyClazz");
  }
}

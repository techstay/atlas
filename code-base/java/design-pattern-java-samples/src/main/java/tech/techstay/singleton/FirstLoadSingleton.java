package tech.techstay.singleton;

public class FirstLoadSingleton {
  private static FirstLoadSingleton singleton;

  static {
    singleton = new FirstLoadSingleton();
  }

  private FirstLoadSingleton() {}

  public static FirstLoadSingleton getSingleton() {
    return singleton;
  }
}

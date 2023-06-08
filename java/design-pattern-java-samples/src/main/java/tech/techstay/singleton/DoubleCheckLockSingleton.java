package tech.techstay.singleton;

public class DoubleCheckLockSingleton {
  private static volatile DoubleCheckLockSingleton singleton;

  private DoubleCheckLockSingleton() {}

  public static DoubleCheckLockSingleton getSingleton() {
    if (singleton == null) {
      synchronized (DoubleCheckLockSingleton.class) {
        if (singleton == null) {
          singleton = new DoubleCheckLockSingleton();
        }
      }
    }
    return singleton;
  }
}

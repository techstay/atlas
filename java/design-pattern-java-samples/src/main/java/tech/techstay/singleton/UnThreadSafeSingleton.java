package tech.techstay.singleton;

// 懒汉式（非线程安全）
public class UnThreadSafeSingleton {
  private static UnThreadSafeSingleton singleton;

  private UnThreadSafeSingleton() {}

  public static UnThreadSafeSingleton getSingleton() {
    if (singleton == null) {
      singleton = new UnThreadSafeSingleton();
    }
    return singleton;
  }
}

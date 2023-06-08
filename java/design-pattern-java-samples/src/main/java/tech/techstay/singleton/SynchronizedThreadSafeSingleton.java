package tech.techstay.singleton;

public class SynchronizedThreadSafeSingleton {
  private static SynchronizedThreadSafeSingleton singleton;

  private SynchronizedThreadSafeSingleton() {

  }

  public static synchronized SynchronizedThreadSafeSingleton getSingleton() {
    if (singleton == null) {
      singleton = new SynchronizedThreadSafeSingleton();
    }
    return singleton;
  }
}

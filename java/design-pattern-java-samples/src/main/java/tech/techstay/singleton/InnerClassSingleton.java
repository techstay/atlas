package tech.techstay.singleton;

public class InnerClassSingleton {
  private InnerClassSingleton() {}

  public static InnerClassSingleton getSingleton() {
    return Inner.singleton;
  }

  private static class Inner {
    private static InnerClassSingleton singleton = new InnerClassSingleton();
  }
}

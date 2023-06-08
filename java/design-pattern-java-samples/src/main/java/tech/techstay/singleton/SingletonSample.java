package tech.techstay.singleton;

public class SingletonSample {
  public static void main(String[] args) {
    System.out.println("懒汉式（非线程安全）的单例");
    UnThreadSafeSingleton unThreadSafeSingleton = UnThreadSafeSingleton.getSingleton();

    System.out.println("懒汉式（线程安全）的单例");
    SynchronizedThreadSafeSingleton synchronizedThreadSafeSingleton =
        SynchronizedThreadSafeSingleton.getSingleton();

    System.out.println("饿汉式（静态域）");
    FirstLoadSingleton firstLoadSingleton = FirstLoadSingleton.getSingleton();

    System.out.println("双检锁方式");
    DoubleCheckLockSingleton doubleCheckLockSingleton = DoubleCheckLockSingleton.getSingleton();

    System.out.println("内部类方式");
    InnerClassSingleton innerClassSingleton = InnerClassSingleton.getSingleton();

    System.out.println("枚举方式静态类");
    EnumSingleton enumSingleton = EnumSingleton.Instance;
    String data = enumSingleton.getData();
  }
}

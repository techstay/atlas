package yitian.study.singleton;

/**
 * 懒汉式（非线程安全）
 */
public class UnThreadSafeSingleton {
    private UnThreadSafeSingleton() {
    }

    private static UnThreadSafeSingleton singleton;

    public static UnThreadSafeSingleton getSingleton() {
        if (singleton == null) {
            singleton = new UnThreadSafeSingleton();
        }
        return singleton;
    }
}

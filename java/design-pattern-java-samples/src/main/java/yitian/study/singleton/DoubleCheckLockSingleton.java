package yitian.study.singleton;

public class DoubleCheckLockSingleton {
    private volatile static DoubleCheckLockSingleton singleton;

    private DoubleCheckLockSingleton() {
    }

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

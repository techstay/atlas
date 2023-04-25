package yitian.study.singleton;

public class SynchronizedThreadSafeSingleton {
    private static SynchronizedThreadSafeSingleton singleton;

    private SynchronizedThreadSafeSingleton() {

    }

    public synchronized static SynchronizedThreadSafeSingleton getSingleton() {
        if (singleton == null) {
            singleton = new SynchronizedThreadSafeSingleton();
        }
        return singleton;
    }
}

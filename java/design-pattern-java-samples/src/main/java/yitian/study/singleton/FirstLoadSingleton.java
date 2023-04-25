package yitian.study.singleton;

public class FirstLoadSingleton {
    private static FirstLoadSingleton singleton;

    private FirstLoadSingleton() {
    }

    static {
        singleton = new FirstLoadSingleton();
    }

    public static FirstLoadSingleton getSingleton() {
        return singleton;
    }
}

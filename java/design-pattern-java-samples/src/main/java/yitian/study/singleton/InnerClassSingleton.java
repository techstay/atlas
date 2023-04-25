package yitian.study.singleton;

public class InnerClassSingleton {
    private static class Inner {
        private static InnerClassSingleton singleton = new InnerClassSingleton();
    }

    private InnerClassSingleton() {
    }

    public static InnerClassSingleton getSingleton() {
        return Inner.singleton;
    }
}

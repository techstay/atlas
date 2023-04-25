package yitian.study.singleton;

public enum EnumSingleton {
    Instance;

    private String data;

    EnumSingleton() {
        //在构造方法中进行初始化
        data = "Some data";
    }

    public String getData() {
        return data;
    }
}

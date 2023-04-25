package yitian.study.prototype;

public class LargeObjectFactory {
    private LargeObject obj;

    public LargeObjectFactory() {
        init();
    }

    private void init() {
        obj = new LargeObject();
        obj.setProp1("prop1");
        obj.setProp2("prop2");
        obj.setProp3("prop3");
    }

    public LargeObject getLargeObject() {
        return obj.clone();
    }
}

package yitian.study.prototype;

public class LargeObject implements Cloneable<LargeObject> {
    private String prop1;
    private String prop2;
    private String prop3;

    public String getProp1() {
        return prop1;
    }

    public void setProp1(String prop1) {
        this.prop1 = prop1;
    }

    public String getProp2() {
        return prop2;
    }

    public void setProp2(String prop2) {
        this.prop2 = prop2;
    }

    public String getProp3() {
        return prop3;
    }

    public void setProp3(String prop3) {
        this.prop3 = prop3;
    }

    @Override
    public LargeObject clone() {
        LargeObject obj = new LargeObject();
        obj.setProp1(prop1);
        obj.setProp2(prop2);
        obj.setProp3(prop3);
        return obj;
    }

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("LargeObject{");
        sb.append("prop1='").append(prop1).append('\'');
        sb.append(", prop2='").append(prop2).append('\'');
        sb.append(", prop3='").append(prop3).append('\'');
        sb.append('}');
        return sb.toString();
    }
}

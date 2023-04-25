package yitian.study.prototype;

import yitian.study.Sample;

public class PrototypeSample implements Sample {
    @Override
    public void run() {
        LargeObjectFactory factory = new LargeObjectFactory();
        LargeObject obj = factory.getLargeObject();
        System.out.println(obj);
    }
}

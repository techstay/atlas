package yitian.study.facade;

import yitian.study.Sample;

public class FacadeSample implements Sample {
    @Override
    public void run() {
        FactoryFacade facade=new FactoryFacade();
        Product product=facade.service("A");
        System.out.println(product.getName());
    }
}

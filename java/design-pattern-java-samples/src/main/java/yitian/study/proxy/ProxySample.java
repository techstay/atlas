package yitian.study.proxy;

import yitian.study.Sample;

public class ProxySample implements Sample {
    @Override
    public void run() {
        Resource resource = new StringResource("Some resource");
        System.out.println(resource.getResource());

        Resource resourceProxy = new StringResourceProxy(resource);
        System.out.println(resourceProxy.getResource());
    }
}

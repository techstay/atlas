package tech.techstay.proxy;

public class ProxySample {
  public static void main(String[] args) {
    Resource resource = new StringResource("Some resource");
    System.out.println(resource.getResource());

    Resource resourceProxy = new StringResourceProxy(resource);
    System.out.println(resourceProxy.getResource());
  }
}

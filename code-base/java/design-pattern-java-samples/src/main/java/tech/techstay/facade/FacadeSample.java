package tech.techstay.facade;

public class FacadeSample {
  public static void main(String[] args) {
    FactoryFacade facade = new FactoryFacade();
    Product product = facade.service("A");
    System.out.println(product.getName());
  }
}

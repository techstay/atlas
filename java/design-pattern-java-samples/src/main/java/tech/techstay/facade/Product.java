package tech.techstay.facade;

public class Product {
  private String name;

  public Product(String name) {
    this.name = name + " 对应的产品";
  }

  public String getName() {
    return name;
  }
}

package tech.techstay.facade;

public class Factory {
  public Product produce(Request request) {
    return new Product(request.getMsg());
  }
}

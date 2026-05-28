package tech.techstay.facade;

public class FactoryFacade {
  private Factory factory;

  public FactoryFacade() {
    this.factory = new Factory();
  }

  public Product service(String msg) {
    Request request = new Request(msg);
    return factory.produce(request);
  }
}

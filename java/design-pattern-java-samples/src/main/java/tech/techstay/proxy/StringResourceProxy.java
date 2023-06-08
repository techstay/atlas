package tech.techstay.proxy;

public class StringResourceProxy implements Resource {
  private Resource resource;

  public StringResourceProxy(Resource resource) {
    this.resource = resource;
  }

  @Override
  public String getResource() {
    return "In proxy: " + resource.getResource();
  }
}

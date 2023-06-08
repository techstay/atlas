package tech.techstay.proxy;

public class StringResource implements Resource {
  private String content;

  public StringResource(String content) {
    this.content = content;
  }


  @Override
  public String getResource() {
    return content;
  }
}

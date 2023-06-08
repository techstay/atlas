package tech.techstay.prototype;

public class PrototypeSample {
  public static void main(String[] args) {
    LargeObjectFactory factory = new LargeObjectFactory();
    LargeObject obj = factory.getLargeObject();
    System.out.println(obj);
  }
}

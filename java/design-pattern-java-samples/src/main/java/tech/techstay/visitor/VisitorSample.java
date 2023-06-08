package tech.techstay.visitor;

public class VisitorSample {
  public static void main(String[] args) {
    Visitor visitor = new HouseVisitor();
    House house = new House();
    house.accept(visitor);
  }
}

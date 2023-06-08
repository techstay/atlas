package tech.techstay.factory;


public class FactorySample {
  public static void main(String[] args) {
    ShapeFactory factory = new ShapeFactory();
    Shape square = factory.getShape(Shape.SQUARE);
    square.print();
    Shape rectangle = factory.getShape(Shape.RECTANGLE);
    rectangle.print();
    Shape circle = factory.getShape(Shape.CIRCLE);
    circle.print();
  }
}

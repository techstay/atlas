package tech.techstay.factory;


public class ShapeFactory {
  public Shape getShape(int shapeType) {
    return switch (shapeType) {
      case Shape.SQUARE -> new Square();
      case Shape.CIRCLE -> new Circle();
      case Shape.RECTANGLE -> new Rectangle();
      default -> null;
    };
  }
}

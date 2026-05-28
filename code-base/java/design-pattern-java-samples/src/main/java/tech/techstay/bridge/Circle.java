package tech.techstay.bridge;

public class Circle implements Shape {
  private Color color;

  public Circle(Color color) {
    this.color = color;
  }

  @Override
  public String getShape() {
    return color.getColor().concat(" ").concat("Circle");
  }

}

package tech.techstay.bridge;

public class Square implements Shape {
  private Color color;

  public Square(Color color) {
    this.color = color;
  }

  @Override
  public String getShape() {
    return color.getColor() + " " + "Square";
  }
}

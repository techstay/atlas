package tech.techstay.decorator;

public abstract class ColorDecorator implements Shape {
  protected Shape shape;

  public ColorDecorator(Shape shape) {
    this.shape = shape;
  }

}


class RedDecorator extends ColorDecorator {
  public RedDecorator(Shape shape) {
    super(shape);
  }

  @Override
  public String getShape() {
    return "红色的" + shape.getShape();
  }
}


class BlueDecorator extends ColorDecorator {
  public BlueDecorator(Shape shape) {
    super(shape);
  }

  @Override
  public String getShape() {
    return "绿色的" + shape.getShape();
  }
}

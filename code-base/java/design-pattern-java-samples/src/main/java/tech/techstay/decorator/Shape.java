package tech.techstay.decorator;

public interface Shape {
  String getShape();
}


class Square implements Shape {

  @Override
  public String getShape() {
    return "正方形";
  }
}


class Circle implements Shape {

  @Override
  public String getShape() {
    return "圆";
  }
}

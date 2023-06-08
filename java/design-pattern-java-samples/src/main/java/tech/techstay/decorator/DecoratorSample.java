package tech.techstay.decorator;

public class DecoratorSample {
  public static void main(String[] args) {
    Shape square = new Square();
    Shape circle = new Circle();

    Shape redSquare = new RedDecorator(square);
    Shape blueCircle = new BlueDecorator(circle);
    System.out.println(redSquare.getShape());
    System.out.println(blueCircle.getShape());
  }
}

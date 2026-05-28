package tech.techstay.bridge;

public class BridgeSample {
  public static void main(String[] args) {
    Shape redCircle = new Circle(new Red());
    Shape yellowSquare = new Square(new Yellow());

    System.out.println(redCircle.getShape());
    System.out.println(yellowSquare.getShape());
  
  }
}



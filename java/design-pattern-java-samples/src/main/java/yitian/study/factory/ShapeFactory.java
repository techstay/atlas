package yitian.study.factory;


public class ShapeFactory {
    public Shape getShape(int shapeType) {
        Shape shape = null;
        switch (shapeType) {
            case Shape.Square:
                shape = new Square();
                break;
            case Shape.Circle:
                shape = new Circle();
                break;
            case Shape.Rectangle:
                shape = new Rectangle();
                break;
        }
        return shape;
    }
}

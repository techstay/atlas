package yitian.study.factory;


import yitian.study.Sample;

public class FactorySample implements Sample {

    @Override
    public void run() {
        ShapeFactory factory = new ShapeFactory();
        Shape square = factory.getShape(Shape.Square);
        square.print();
        Shape rectangle = factory.getShape(Shape.Rectangle);
        rectangle.print();
        Shape circle = factory.getShape(Shape.Circle);
        circle.print();
    }
}

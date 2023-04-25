package yitian.study.decorator;

import yitian.study.Sample;

public class DecoratorSample implements Sample {
    @Override
    public void run() {
        Shape square = new Square();
        Shape circle = new Circle();

        Shape redSquare = new RedDecorator(square);
        Shape blueCircle = new BlueDecorator(circle);
        System.out.println(redSquare.getShape());
        System.out.println(blueCircle.getShape());
    }
}

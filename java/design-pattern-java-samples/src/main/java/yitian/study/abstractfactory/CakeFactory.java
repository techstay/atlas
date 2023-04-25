package yitian.study.abstractfactory;

public class CakeFactory implements AbstractFactory {
    @Override
    public Spice getSpice() {
        return () -> "糖";
    }

    @Override
    public Food getFood() {
        return () -> "蛋糕";
    }
}

package yitian.study.strategy;

public class Calculator {
    private Strategy strategy;

    public void setStrategy(Strategy strategy) {
        this.strategy = strategy;
    }

    public double calc(double a, double b) {
        return strategy.cal(a, b);
    }
}

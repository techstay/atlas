package yitian.study.strategy;

public interface Strategy {
    double cal(double a, double b);
}

class FastStrategy implements Strategy {

    @Override
    public double cal(double a, double b) {
        return (a + b) / 2;
    }
}

class SlowStrategy implements Strategy {

    @Override
    public double cal(double a, double b) {
        return Math.sqrt(a * b);
    }
}

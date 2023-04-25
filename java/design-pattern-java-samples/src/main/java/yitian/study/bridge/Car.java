package yitian.study.bridge;

public abstract class Car {
    protected Road road;
    protected String car;

    public Car(Road road, String car) {
        this.road = road;
        this.car = car;
    }

    abstract void drive();
}

class Jeep extends Car {
    public Jeep(Road road, String car) {
        super(road, car);
    }

    @Override
    public void drive() {
        System.out.println(car + "on" + road.getName());
    }
}

class SUV extends Car {
    public SUV(Road road, String car) {
        super(road, car);
    }

    @Override
    void drive() {
        System.out.println(car + "on" + road.getName());
    }
}
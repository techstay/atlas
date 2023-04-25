package yitian.study.flyweight;

import java.util.HashMap;

public class ObjectPool {
    private HashMap<Integer, Car> carMap = new HashMap<>();
    private HashMap<Integer, Motorcycle> motorcycleMap = new HashMap<>();

    public void putCar(Car car) {
        carMap.put(car.getId(), car);
    }

    public Car getCar(int id) {
        return carMap.get(id);
    }

    public void putMotorcycle(Motorcycle motorcycle) {
        motorcycleMap.put(motorcycle.getId(), motorcycle);
    }

    public Motorcycle getMotorcycle(int id) {
        return motorcycleMap.get(id);
    }
}

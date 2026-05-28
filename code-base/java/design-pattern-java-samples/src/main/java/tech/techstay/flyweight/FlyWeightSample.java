package tech.techstay.flyweight;

public class FlyWeightSample {
  public static void main(String[] args) {
    ObjectPool pool = new ObjectPool();
    pool.putCar(new Car(1));
    pool.putCar(new Car(2));
    pool.putCar(new Car(3));
    pool.putCar(new Car(4));
    pool.putCar(new Car(5));

    pool.putMotorcycle(new Motorcycle(1));
    pool.putMotorcycle(new Motorcycle(2));
    pool.putMotorcycle(new Motorcycle(3));

    pool.getCar(1).show();
    pool.getCar(2).show();
    pool.getCar(3).show();

    pool.getMotorcycle(1).show();
    pool.getMotorcycle(2).show();

  }
}

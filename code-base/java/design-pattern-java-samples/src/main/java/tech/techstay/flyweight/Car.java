package tech.techstay.flyweight;

public class Car implements Visible {
  private int id;

  public Car(int id) {
    this.id = id;
  }

  public int getId() {
    return id;
  }

  @Override
  public void show() {
    System.out.println("This is a car " + id);
  }
}

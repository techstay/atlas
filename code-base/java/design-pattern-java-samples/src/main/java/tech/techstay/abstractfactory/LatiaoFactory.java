package tech.techstay.abstractfactory;

public class LatiaoFactory implements AbstractFactory {
  @Override
  public Spice getSpice() {
    return () -> "辣椒";
  }

  @Override
  public Food getFood() {
    return () -> "辣条";
  }
}

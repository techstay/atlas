package tech.techstay.abstractfactory;

public class SaltyEggFactory implements AbstractFactory {
  @Override
  public Spice getSpice() {
    return () -> "盐";
  }

  @Override
  public Food getFood() {
    return () -> "咸鸭蛋";
  }
}

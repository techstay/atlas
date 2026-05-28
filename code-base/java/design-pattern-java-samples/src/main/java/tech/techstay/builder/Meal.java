package tech.techstay.builder;

public class Meal {
  private Drink drink;
  private Spice spice;
  private Staple staple;

  public void setDrink(Drink drink) {
    this.drink = drink;
  }

  public void setSpice(Spice spice) {
    this.spice = spice;
  }

  public void setStaple(Staple staple) {
    this.staple = staple;
  }

  void showMeal() {
    System.out.println(staple.getInfo() + ": " + spice.getInfo() + ": " + drink.getInfo());
  }
}

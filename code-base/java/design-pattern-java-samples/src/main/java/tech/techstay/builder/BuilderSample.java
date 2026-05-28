package tech.techstay.builder;

public class BuilderSample {
  public static void main(String[] args) {
    MealBuilder builder = new MealBuilder();
    builder.addDrink(() -> "啤酒");
    builder.addSpice(() -> "辣椒");
    builder.addStaple(() -> "炸鸡");
    Meal meal = builder.build();
    meal.showMeal();
  }
}

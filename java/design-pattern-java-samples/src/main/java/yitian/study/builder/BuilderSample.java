package yitian.study.builder;

import yitian.study.Sample;

public class BuilderSample implements Sample {
    @Override
    public void run() {
        MealBuilder builder = new MealBuilder();
        builder.addDrink(() -> "啤酒");
        builder.addSpice(() -> "辣椒");
        builder.addStaple(() -> "炸鸡");
        Meal meal = builder.build();
        meal.showMeal();
    }
}

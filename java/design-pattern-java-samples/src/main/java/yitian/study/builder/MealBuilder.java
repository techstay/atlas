package yitian.study.builder;

public class MealBuilder {
    private Meal meal;

    public MealBuilder() {
        meal = new Meal();
    }

    public MealBuilder addSpice(Spice spice) {
        meal.setSpice(spice);
        return this;
    }

    public MealBuilder addStaple(Staple staple) {
        meal.setStaple(staple);
        return this;
    }

    public MealBuilder addDrink(Drink drink) {
        meal.setDrink(drink);
        return this;
    }

    public Meal build() {
        return meal;
    }
}

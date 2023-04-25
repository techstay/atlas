package yitian.study.abstractfactory;

import yitian.study.Sample;

public class AbstractFactorySample implements Sample {
    @Override
    public void run() {
        AbstractFactory factory = new CakeFactory();
        Spice spice = factory.getSpice();
        Food food = factory.getFood();
        printSpiceAndFood(spice, food);

        factory = new LatiaoFactory();
        spice = factory.getSpice();
        food = factory.getFood();
        printSpiceAndFood(spice, food);

        factory = new SaltyEggFactory();
        spice = factory.getSpice();
        food = factory.getFood();
        printSpiceAndFood(spice, food);
    }

    private static void printSpiceAndFood(Spice spice, Food food) {
        System.out.println("调料:" + spice.getSpice() + "," + "食物:" + food.getFood());
    }
}

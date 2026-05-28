package tech.techstay.template;

public abstract class HowToMakeMeal {
  public abstract void buyFood();

  protected abstract void makeMeal();

  protected abstract void haveMeal();

  protected abstract void washDishes();

  public final void doIt() {
    buyFood();
    makeMeal();
    haveMeal();
    washDishes();
  }
}


class HowToMakeMealImpl extends HowToMakeMeal {

  @Override
  public void buyFood() {
    System.out.println("买菜");
  }

  @Override
  public void makeMeal() {
    System.out.println("做饭");
  }

  @Override
  public void haveMeal() {
    System.out.println("吃饭");
  }

  @Override
  public void washDishes() {
    System.out.println("洗碗");
  }
}

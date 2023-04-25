package yitian.study.template;

public abstract class HowToMakeMeal {
    public abstract void buyFood();

    protected abstract void makeMeal();

    protected abstract void haveMeal();

    protected abstract void washDished();

    public void doIt() {
        buyFood();
        makeMeal();
        haveMeal();
        washDished();
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
    public void washDished() {
        System.out.println("洗碗");
    }
}
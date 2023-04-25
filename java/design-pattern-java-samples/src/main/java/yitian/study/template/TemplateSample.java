package yitian.study.template;

import yitian.study.Sample;

public class TemplateSample implements Sample {
    @Override
    public void run() {
        HowToMakeMeal howToMakeMeal = new HowToMakeMealImpl();
        howToMakeMeal.doIt();
    }
}

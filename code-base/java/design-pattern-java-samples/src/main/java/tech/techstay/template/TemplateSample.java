package tech.techstay.template;

public class TemplateSample {
  public static void main(String[] args) {
    HowToMakeMeal howToMakeMeal = new HowToMakeMealImpl();
    howToMakeMeal.doIt();
  }
}

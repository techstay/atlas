package tech.techstay.composite;

public class CompositeSample {
  public static void main(String[] args) {
    MenuItem mainMenu = new MenuItem("主菜单");
    MenuItem subItem1 = new MenuItem("子菜单项1");
    MenuItem subItem2 = new MenuItem("子菜单项2");

    mainMenu.addMenuItem(subItem1);
    mainMenu.addMenuItem(subItem2);

    System.out.println(mainMenu);
  }
}

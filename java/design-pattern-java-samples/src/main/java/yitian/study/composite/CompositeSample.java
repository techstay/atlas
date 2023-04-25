package yitian.study.composite;

import yitian.study.Sample;

public class CompositeSample implements Sample {
    @Override
    public void run() {
        MenuItem mainMenu = new MenuItem("主菜单");
        MenuItem subItem1 = new MenuItem("子菜单项1");
        MenuItem subItem2 = new MenuItem("子菜单项2");

        mainMenu.addMenuItem(subItem1);
        mainMenu.addMenuItem(subItem2);

        System.out.println(mainMenu);
    }
}

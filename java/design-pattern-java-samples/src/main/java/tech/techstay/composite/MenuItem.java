package tech.techstay.composite;

import java.util.ArrayList;
import java.util.List;

public class MenuItem {
  private List<MenuItem> subMenu;
  private String name;

  public MenuItem(String name) {
    this.name = name;
    subMenu = new ArrayList<>();
  }

  public void addMenuItem(MenuItem item) {
    subMenu.add(item);
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public List<MenuItem> getSubMenu() {
    return subMenu;
  }

  @Override
  public String toString() {
    StringBuilder sb = new StringBuilder();
    sb.append(name).append("\n");
    for (MenuItem item : subMenu) {
      sb.append("    " + item);
    }
    return sb.toString();
  }
}

package tech.techstay.enums;

enum TrafficLight {
  RED("Stop"), GREEN("Go"), YELLOW("Slow down");

  private final String description;

  TrafficLight(String desc) {
    description = desc;
  }

  public String getDescription() {
    return description;
  }

  public TrafficLight turn() {
    return switch (this) {
      case RED -> YELLOW;
      case YELLOW -> GREEN;
      case GREEN -> RED;
    };
  }
}


public class EnumDemo {
  public static void main(String[] args) {
    TrafficLight light = TrafficLight.RED;
    for (int i = 0; i < 5; i++) {
      System.out.format("%s: %s%n", light, light.getDescription());
      light = light.turn();
    }
  }
}

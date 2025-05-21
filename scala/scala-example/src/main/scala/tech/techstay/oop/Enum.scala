package tech.techstay.oop

enum TrafficLight:
  def turn(): TrafficLight = this match
    case RED    => GREEN
    case GREEN  => YELLOW
    case YELLOW => RED
  case RED, GREEN, YELLOW

@main def enums(): Unit =
  var trafficLight = TrafficLight.RED
  println(trafficLight)
  println(trafficLight.turn())
  println(trafficLight.turn())

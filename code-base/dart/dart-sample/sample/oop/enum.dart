void main(List<String> args) {
  var trafficLight = TrafficLight.red;
  print(trafficLight);
  print(trafficLight.turn());

  for (var e in TrafficLight.values) {
    print(e.name);
  }
}

enum TrafficLight {
  red,
  yellow,
  green;

  TrafficLight turn() =>
      switch (this) { red => yellow, yellow => green, green => red };
}

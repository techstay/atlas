package yitian.study.state;

import yitian.study.Sample;

public class StateSample implements Sample {
    @Override
    public void run() {
        TrafficLight light = new TrafficLight();
        light.turn();
        light.turn();
        light.turn();
        light.turn();
    }
}

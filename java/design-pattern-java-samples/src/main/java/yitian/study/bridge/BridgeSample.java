package yitian.study.bridge;

import yitian.study.Sample;

public class BridgeSample implements Sample {
    @Override
    public void run() {
        Road highway = new HighWayRoad();
        Road street = new TownStreetRoad();

        Car jeep = new Jeep(highway, "吉普");
        jeep.drive();

        Car suv = new SUV(street, "SUV");
        suv.drive();
    }
}

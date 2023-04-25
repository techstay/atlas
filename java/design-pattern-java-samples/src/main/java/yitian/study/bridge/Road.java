package yitian.study.bridge;

public interface Road {
    String getName();
}

class HighWayRoad implements Road {

    @Override
    public String getName() {
        return "高速公路";
    }
}

class TownStreetRoad implements Road {

    @Override
    public String getName() {
        return "市区公路";
    }
}
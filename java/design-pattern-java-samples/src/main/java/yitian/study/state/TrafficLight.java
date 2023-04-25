package yitian.study.state;

public class TrafficLight {
    private State redState = new RedState();
    private State yellowState = new YellowState();
    private State greenState = new GreenState();

    private State current = greenState;

    public void turn() {
        if (current == greenState) {
            current = yellowState;
            current.show();
        } else if (current == yellowState) {
            current = redState;
            current.show();
        } else {
            current = greenState;
            current.show();
        }
    }
}


interface State {
    void show();
}

class RedState implements State {

    @Override
    public void show() {
        System.out.println("交通灯变红了");

    }
}

class YellowState implements State {

    @Override
    public void show() {
        System.out.println("交通灯变黄了");

    }
}

class GreenState implements State {

    @Override
    public void show() {
        System.out.println("交通灯变绿了");

    }
}
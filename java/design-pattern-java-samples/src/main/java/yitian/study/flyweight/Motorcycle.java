package yitian.study.flyweight;

public class Motorcycle implements Visible {
    private int id;

    public Motorcycle(int id) {
        this.id = id;
    }

    public int getId() {
        return id;
    }

    @Override
    public void show() {
        System.out.println("THis is a motorcycle "+id);
    }
}

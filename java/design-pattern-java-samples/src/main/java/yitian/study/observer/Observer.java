package yitian.study.observer;

public interface Observer<T> {
    void onChanged(T arg);
}

class ObserverImpl<T> implements Observer<T> {
    private String name;

    public ObserverImpl(String name) {
        this.name = name;
    }

    @Override
    public void onChanged(T arg) {
        System.out.println(name + " receives:" + arg);
    }
}
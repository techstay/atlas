package yitian.study.observer;

import yitian.study.Sample;

public class ObserverSample implements Sample {
    @Override
    public void run() {
        Observable<String> sender = new Observable("value1");
        Observer<String> receiver1 = new ObserverImpl<>("ob1");
        Observer<String> receiver2 = new ObserverImpl<>("ob2");
        sender.addObserver(receiver1);
        sender.addObserver(receiver2);

        sender.update("value2");
        sender.update("value3");

    }
}

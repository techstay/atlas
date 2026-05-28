package tech.techstay.observer;

public class ObserverSample {
  public static void main(String[] args) {
    Observable<String> sender = new Observable<>("value1");
    Observer<String> receiver1 = new ObserverImpl<>("foo");
    Observer<String> receiver2 = new ObserverImpl<>("bar");

    sender.addObserver(receiver1);
    sender.addObserver(receiver2);

    sender.update("value2");
    sender.update("value3");

  }
}

package tech.techstay.observer;

import java.util.ArrayList;
import java.util.List;

public class Observable<T> {
  private List<Observer<T>> observers = new ArrayList<>();
  private T content;

  public Observable(T value) {
    content = value;
  }

  public void addObserver(Observer<T> observer) {
    observers.add(observer);
  }

  public void removeObserver(Observer<T> observer) {
    observers.remove(observer);
  }

  protected void update(T value) {
    content = value;
    for (Observer<T> ob : observers) {
      ob.onChanged(content);
    }
  }
}

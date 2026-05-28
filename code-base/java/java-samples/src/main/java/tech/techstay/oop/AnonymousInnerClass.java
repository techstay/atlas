package tech.techstay.oop;

public class AnonymousInnerClass {
  public static void main(String[] args) throws InterruptedException {

    Runnable task = new Runnable() {
      @Override
      public void run() {
        System.out.println("doing something");
      }
    };

    Thread thread = new Thread(task);
    thread.start();
    Thread.sleep(200);
  }
}

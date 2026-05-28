package tech.techstay.oop;

public class Lambda {

  public static void main(String[] args) throws InterruptedException {
    Runnable task = () -> {
      System.out.println("my tasks");
    };
    new Thread(task).start();
    Thread.sleep(300);
  }
}

package tech.techstay.concurrency;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.stream.IntStream;

public class RunnableDemo {
  public static void main(String[] args) {
    try (ExecutorService executor = Executors.newCachedThreadPool()) {
      IntStream.rangeClosed(1, 10).forEach(i -> {
        executor.execute(task(i));
      });
      System.out.println("all tasks submitted");
      executor.shutdown();
    }
  }

  static Runnable task(int index) {
    return () -> {
      try {
        System.out.println(Thread.currentThread().getName());
        TimeUnit.MILLISECONDS.sleep(150);
        System.out.format("task %d finished%n", index);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }

    };
  }


}

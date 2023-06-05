package tech.techstay.concurrency;

import java.util.concurrent.CompletableFuture;
import java.util.function.Function;

public class CompletableFutureDemo {
  public static void main(String[] args) {
    Function<Integer, Integer> f1 = i -> {
      try {
        Thread.sleep(300);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
      return i + 100;
    };
    Function<Integer, Integer> f2 = i -> {
      try {
        Thread.sleep(300);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
      return i + 100;
    };
    Function<Integer, Integer> f3 = i -> {
      try {
        Thread.sleep(300);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
      return i + 100;
    };

    CompletableFuture<Integer> task =
        CompletableFuture.completedFuture(f1.apply(1)).thenApplyAsync(f2).thenApplyAsync(f3);
    System.out.println(task.join());
  }

}

package tech.techstay.concurrency;

import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.stream.IntStream;

public class CallableDemo {
  public static void main(String[] args) {
    try (ExecutorService executor = Executors.newCachedThreadPool()) {
      int sum = 0;
      List<Future<Integer>> futures =
          IntStream.rangeClosed(1, 100).mapToObj(i -> task(i)).map(executor::submit).toList();
      executor.shutdown();
      sum = futures.stream().mapToInt(e -> getResultFromFuture(e)).sum();
      System.out.println(sum);
    }
  }

  static int getResultFromFuture(Future<Integer> future) {
    try {
      return future.get();
    } catch (Exception e) {
      throw new RuntimeException(e);
    }
  }

  static Callable<Integer> task(int index) {
    return () -> {
      Thread.sleep(500);
      return index;
    };
  }
}

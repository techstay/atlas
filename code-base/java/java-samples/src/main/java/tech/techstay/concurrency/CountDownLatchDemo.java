package tech.techstay.concurrency;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.IntStream;

public class CountDownLatchDemo {
  public static void main(String[] args) throws InterruptedException {
    try (ExecutorService executorService = Executors.newSingleThreadExecutor()) {
      List<Integer> result = new ArrayList<>();
      CountDownLatch count = new CountDownLatch(10);

      IntStream.rangeClosed(1, 10).forEach(i -> {
        executorService.submit(() -> {
          try {
            Thread.sleep(150);
            result.add(i);
            count.countDown();
          } catch (InterruptedException e) {
            e.printStackTrace();
          }
        });
      });
      executorService.shutdown();
      count.await();
      System.out.println(result.stream().mapToInt(i -> i).sum());
    }
  }

}

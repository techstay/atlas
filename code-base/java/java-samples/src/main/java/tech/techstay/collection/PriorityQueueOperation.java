package tech.techstay.collection;

import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.stream.IntStream;

public class PriorityQueueOperation {
  public static void main(String[] args) {
    PriorityQueue<Integer> queue1 = new PriorityQueue<>();
    queue1.offer(1);
    queue1.offer(50);
    queue1.offer(100);
    queue1.offer(2);

    // the smallest element has the highest priority by default
    System.out.println(IntStream.generate(queue1::poll).limit(queue1.size()).boxed().toList());

    // reversed priority
    PriorityQueue<Integer> queue2 = new PriorityQueue<>(Collections.reverseOrder());
    queue2.addAll(List.of(1, 50, 100, 2));

    System.out.println(IntStream.generate(queue2::poll).limit(queue2.size()).boxed().toList());

    // custom priority
    // the larger rightmost digit, the higher priority
    PriorityQueue<Integer> queue3 = new PriorityQueue<>((b, a) -> (a % 10) - (b % 10));
    queue3.addAll(List.of(11, 21, 19, 8, 6));

    System.out.println(IntStream.generate(queue3::poll).limit(queue3.size()).boxed().toList());
  }

}

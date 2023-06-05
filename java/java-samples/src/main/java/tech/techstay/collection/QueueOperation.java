package tech.techstay.collection;

import java.util.LinkedList;
import java.util.NoSuchElementException;
import java.util.Queue;

public class QueueOperation {
  public static void main(String[] args) {
    // queues
    Queue<Integer> queue = new LinkedList<>();

    // appending elements
    queue.offer(1);
    System.out.println(queue);
    queue.offer(2);
    System.out.println(queue);
    queue.offer(3);
    System.out.println(queue);

    // returning the elements from the head and removing it

    // poll will return null if the queue is empty
    queue.poll();
    System.out.println(queue);
    queue.poll();
    System.out.println(queue);
    // remove will throw an exception if the queue is empty
    queue.remove();
    System.out.println(queue);

    // getting first elements but not removing it from the queue

    // returning null if the queue is empty
    Integer i = queue.peek();

    try {
      // throwing exceptions if the queue is empty
      i = queue.element();
    } catch (NoSuchElementException e) {
      System.out.println("caught an exception");
      e.printStackTrace();
    }
  }

}

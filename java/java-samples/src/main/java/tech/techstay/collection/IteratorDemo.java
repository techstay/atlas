package tech.techstay.collection;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class IteratorDemo {
  public static void main(String[] args) {
    MyList myList = new MyList(new int[] {1, 2, 3, 4, 5});
    for (int i : myList) {
      System.out.print(i + " ");
    }
    System.out.println();

    // using iterators
    Iterator<Integer> iterator = myList.iterator();
    while (iterator.hasNext()) {
      System.out.print(iterator.next() + " ");
    }
    System.out.println();
  }

}


class MyList implements Iterable<Integer> {
  private int[] array;

  public MyList(int[] array) {
    this.array = array;
  }


  @Override
  public Iterator<Integer> iterator() {
    return new Iterator<>() {
      private int current = 0;

      @Override
      public boolean hasNext() {
        return current < array.length;
      }

      @Override
      public Integer next() {
        if (!hasNext()) {
          throw new NoSuchElementException("No more elements");
        }

        return array[current++];
      }
    };
  }
}

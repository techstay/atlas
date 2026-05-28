package tech.techstay.iterator;

public class IteratorSample {
  public static void main(String[] args) {
    int[] array = {1, 2, 3, 4, 5, 6};
    MyCollection myCollection = new MyCollection(array);

    Iterator iterator = myCollection.getIterator();
    while (iterator.hasNext()) {
      System.out.printf("%d ", iterator.next());
    }
    System.out.println();
  }
}

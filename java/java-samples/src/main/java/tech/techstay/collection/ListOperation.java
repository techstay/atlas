package tech.techstay.collection;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class ListOperation {
  @SuppressWarnings("unused")
  public static void main(String[] args) {
    ArrayList<Integer> list1 = new ArrayList<>();

    LinkedList<Integer> list2 = new LinkedList<>();

    list2.addAll(List.of(1, 2, 3, 4, 5));
    System.out.println(list2);

    // iterating
    for (int i = 0; i < list2.size(); i++) {
      // doing something
      int element = list2.get(i);
    }

    // obtaining elements
    // throwing exceptions when list is empty
    int i = list2.getFirst();


    // removing elements
    // throwing exceptions if list is empty
    list2.removeFirst();

    // stack operations
    list2.push(10);
    list2.peek();
    list2.pop();
  }
}

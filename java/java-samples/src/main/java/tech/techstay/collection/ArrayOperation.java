package tech.techstay.collection;

import java.util.Arrays;
import java.util.Comparator;

public class ArrayOperation {
  public static void main(String[] args) {
    int[] arr1 = new int[] {5, 4, 3, 3, 1};
    Integer[] arr2 = new Integer[5];

    // fill
    Arrays.fill(arr1, 100);
    // setAll
    Arrays.setAll(arr2, i -> (i + 1) * (i + 1));

    System.out.println(Arrays.toString(arr1));
    System.out.println(Arrays.toString(arr2));

    // iterating
    for (int i : arr1) {
      // doing something
    }

    for (int i = 0; i < arr1.length; i++) {
      // doing something
      int element = arr1[i];
    }

    System.out.println("copying:");
    int[] arr3 = Arrays.copyOf(arr1, arr1.length);
    arr1[1] = -1000;
    System.out.println(Arrays.toString(arr1));
    System.out.println(Arrays.toString(arr3));

    System.out.println("sorting:");
    Arrays.sort(arr2);
    System.out.println(Arrays.toString(arr2));
    Arrays.sort(arr2, Comparator.reverseOrder());
    System.out.println(Arrays.toString(arr2));

    System.out.println("searching:");
    int index = Arrays.binarySearch(arr2, 9);
    System.out.println("found 5 at index: " + index);
  }
}

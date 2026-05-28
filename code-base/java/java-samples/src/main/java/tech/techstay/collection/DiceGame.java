package tech.techstay.collection;

import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class DiceGame {
  public static void main(String[] args) {

    Map<Integer, Integer> map = new HashMap<>();
    Random rand = new Random();

    rand.ints(1, 7).limit(1000_000).forEach(i -> {
      int count = map.getOrDefault(i, 0);
      map.put(i, count + 1);
    });

    System.out.println(map);
  }

}

package tech.techstay.interpreter;

import java.util.HashMap;

public class Context {
  private HashMap<Variable, Integer> map = new HashMap<>();

  public void putValue(Variable name, int value) {
    map.put(name, value);
  }

  public int getValue(Variable name) {
    return map.get(name);
  }
}

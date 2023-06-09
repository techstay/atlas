package tech.techstay;

public class Calculator {
  public int plus(int a, int b) {
    return a + b;
  }

  // wrong implementation
  public int minus(int a, int b) {
    return a - b - 1;
  }
  public int multiple(int a,int b){
    throw new UnsupportedOperationException("not yet implemented");
  }
}


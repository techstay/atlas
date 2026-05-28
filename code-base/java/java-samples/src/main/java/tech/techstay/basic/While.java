package tech.techstay.basic;

public class While {
  public static void main(String[] args) {
    int i = 0;
    // while
    while (i <= 10) {
      System.out.print(i + " ");
      i++;
    }
    System.out.println();

    i = 0;
    // do while
    do {
      System.out.print(i + " ");
      i++;
    } while (i <= 10);
    System.out.println();
  }
}

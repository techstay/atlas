package tech.techstay.exception;

public class LostException {
  public static void main(String[] args) {
    try {
      lostException1();
    } catch (VeryImportantException e) {
      System.out.println("I get it!!");
    } catch (RuntimeException e) {
      System.out.println("very important exception is lost!");
    }


    boolean caughtException = false;
    try {
      lostException2();
    } catch (VeryImportantException e) {
      caughtException = true;
      System.out.println("I get it!!");
    } catch (RuntimeException e) {
      caughtException = true;
      System.out.println("very important exception is lost!");
    }
    if (!caughtException) {
      System.out.println("this time we absolutely lost any exception!!");
    }
  }

  static void lostException1() {
    // rethrow exceptions in finally
    try {
      throw new VeryImportantException();
    } finally {
      throw new RuntimeException();
    }

  }

  static void lostException2() {
    // return in finally
    try {
      throw new VeryImportantException();
    } finally {
      return;
    }
  }
}


class VeryImportantException extends RuntimeException {

}

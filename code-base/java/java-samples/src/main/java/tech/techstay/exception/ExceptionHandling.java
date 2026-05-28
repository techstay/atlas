package tech.techstay.exception;

public class ExceptionHandling {
  public static void main(String[] args) {
    try {
      throw new MyException("throwing some custom exception");
    } catch (ArithmeticException | NumberFormatException e) {
      System.out.println("arithmetic exception caught");
    } catch (MyException e) {
      e.printStackTrace();
      System.out.println("custom exception caught!");
    } catch (Exception e) {
      System.out.println("catching the rest exceptions");
      e.printStackTrace();
    } finally {
      System.out.println("doing some cleaning tasks here");
    }
  }
}


class MyException extends RuntimeException {
  MyException(String msg) {
    super(msg);
  }
}

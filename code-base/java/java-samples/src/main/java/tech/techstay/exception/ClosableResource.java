package tech.techstay.exception;

public class ClosableResource {
  public static void main(String[] args) throws Exception {

    try (MyResource my = new MyResource()) {
      my.foo();
    }

  }
}


class MyResource implements AutoCloseable {
  public MyResource() {
    System.out.println("Creating resource");
  }

  public void foo() {
    System.out.println("foo: do something");
  }

  @Override
  public void close() throws Exception {
    System.out.println("Closing resource");
  }
}

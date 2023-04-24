package tech.techstay.basic

class MyClass implements AutoCloseable {
  @Override
  void close() throws Exception {
    println('obj closed.')
  }
}

// automatic resource management
try (def obj = new MyClass()) {
  // do something
} catch (Exception ignored) {
  // if meeting exceptions
}

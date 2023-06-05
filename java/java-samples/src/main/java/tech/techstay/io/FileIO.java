package tech.techstay.io;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class FileIO {
  public static void main(String[] args) throws IOException {

    // reading files
    Path hosts = Paths.get("C:\\Windows\\system32\\drivers\\etc\\hosts");
    Files.readAllLines(hosts).forEach(System.out::println);

    // writing files
    Path file = Paths.get("hello.txt");
    Files.writeString(file, "hello world!");

    if (Files.exists(file)) {
      System.out.println("file created successfully");
      Files.delete(file);
    }
  }

}

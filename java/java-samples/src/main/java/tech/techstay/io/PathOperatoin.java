package tech.techstay.io;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class PathOperatoin {
  public static void main(String[] args) throws IOException {
    // path and file info
    Path hosts = Paths.get("C:\\Windows\\system32\\drivers\\etc\\hosts");
    System.out.println("parent: " + hosts.getParent());
    System.out.println("filename: " + hosts.getFileName());
    System.out.println("root: " + hosts.getRoot());
    System.out.println("exist: " + Files.exists(hosts));
    System.out.println("is regular file: " + Files.isReadable(hosts));
    System.out.println("is directory: " + Files.isDirectory(hosts));
    System.out.println("is executable: " + Files.isExecutable(hosts));
    System.out.println("last modified: " + Files.getLastModifiedTime(hosts));


  }

}

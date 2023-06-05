package tech.techstay.collection;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class ComparableDemo {
  public static void main(String[] args) {
    List<Student> students = new ArrayList<>();
    students.addAll(
        List.of(new Student(2, "lisa", 30), new Student(1, "ada", 16), new Student(0, "wang", 22)));

    System.out.println(students);

    // sort by id
    Collections.sort(students);
    System.out.println(students);

    // sort by name
    students.sort(Comparator.comparing(Student::name));
    System.out.println(students);

    // sort by age
    students.sort(Comparator.comparing(Student::age));
    System.out.println(students);
  }

}


record Student(int id, String name, int age) implements Comparable<Student> {
  @Override
  public int compareTo(Student other) {
    return id - other.id;
  }
}

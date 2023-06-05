package tech.techstay.oop;

import java.util.Objects;
import java.util.StringJoiner;

public class RecordClass {
  public static void main(String[] args) {

    // using java beans
    Employee p1 = new Employee(0, "jack", 18);
    String name = p1.getName();
    System.out.println(p1);

    // using records
    Student s1 = new Student(0, "ada", 18);
    Student s2 = new Student(1, "jack", 22);
    String name2 = s1.name();
    System.out.println(s1);
    System.out.println(s1.compareTo(s2));
  }
}


record Student(int id, String name, int age) implements Comparable<Student> {
  @Override
  public int compareTo(Student o) {
    // comparing by id
    return id - o.id;
  }
}


class Employee {
  private int id;
  private String name;
  private int age;

  public Employee() {}

  public Employee(int id, String name, int age) {
    this.id = id;
    this.name = name;
    this.age = age;
  }

  public int getId() {
    return id;
  }

  public void setId(int id) {
    this.id = id;
  }

  public String getName() {
    return name;
  }

  public void setName(String name) {
    this.name = name;
  }

  public int getAge() {
    return age;
  }

  public void setAge(int age) {
    this.age = age;
  }

  @Override
  public boolean equals(Object o) {
    if (this == o)
      return true;
    if (!(o instanceof Employee employee))
      return false;
    return id == employee.id && age == employee.age && Objects.equals(name, employee.name);
  }

  @Override
  public int hashCode() {
    return Objects.hash(id, name, age);
  }

  @Override
  public String toString() {
    return new StringJoiner(", ", Employee.class.getSimpleName() + "[", "]").add("id=" + id)
        .add("name='" + name + "'").add("age=" + age).toString();
  }
}

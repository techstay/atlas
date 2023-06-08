package tech.techstay.filter;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class FilterSample {
  public static void main(String[] args) {
    List<Person> people = new ArrayList<>();
    people.add(new Person(22, "techstay", Gender.Male));
    people.add(new Person(23, "zhang3", Gender.Female));
    people.add(new Person(24, "li4", Gender.Male));
    people.add(new Person(25, "wang5", Gender.Female));
    people.add(new Person(13, "zhao6", Gender.Male));
    people.add(new Person(10, "ada", Gender.Female));

    Filter<Person> femaleFilter = new FemaleFilter();
    List<Person> women = femaleFilter.filter(people);
    System.out.println("女人们: " + women);

    Filter<Person> ageGreaterThan20Filter = new AgeGreaterThan20Filter();
    List<Person> gt20 = ageGreaterThan20Filter.filter(people);
    System.out.println("大于20的人: " + gt20);

    Filter<Person> andFilter = new AndFilter<>(femaleFilter, ageGreaterThan20Filter);
    System.out.println("既是女性有大于20的人: " + andFilter.filter(people));

    // lambda表达式
    List<Person> men = people.stream().filter(o -> o.getGender() == Gender.Male)
        .filter(o -> o.getAge() >= 23).collect(Collectors.toList());
    System.out.println("大于23的男性: " + men);
  }
}

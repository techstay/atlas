package tech.techstay.filter;

import java.util.ArrayList;
import java.util.List;

public interface Filter<T> {
  List<T> filter(List<T> list);
}


class AgeGreaterThan20Filter implements Filter<Person> {

  @Override
  public List<Person> filter(List<Person> people) {
    List<Person> result = new ArrayList<>();
    for (Person p : people) {
      if (p.getAge() > 20) {
        result.add(p);
      }
    }
    return result;
  }
}


class FemaleFilter implements Filter<Person> {

  @Override
  public List<Person> filter(List<Person> people) {
    List<Person> result = new ArrayList<>();
    for (Person p : people) {
      if (p.getGender() == Gender.Female) {
        result.add(p);
      }
    }
    return result;
  }
}


class AndFilter<T> implements Filter<T> {
  private Filter<T> one;
  private Filter<T> other;

  public AndFilter(Filter<T> one, Filter<T> other) {
    this.one = one;
    this.other = other;
  }

  @Override
  public List<T> filter(List<T> list) {
    List<T> tmp = one.filter(list);
    return other.filter(tmp);
  }
}

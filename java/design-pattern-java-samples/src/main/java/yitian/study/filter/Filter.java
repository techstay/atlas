package yitian.study.filter;

import java.util.ArrayList;
import java.util.List;

public interface Filter {
    List<Person> filter(List<Person> people);
}

class AgeGreaterThan20Filter implements Filter {

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

class FemaleFilter implements Filter {

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

class AndFilter implements Filter {
    private Filter one;
    private Filter other;

    public AndFilter(Filter one, Filter other) {
        this.one = one;
        this.other = other;
    }

    @Override
    public List<Person> filter(List<Person> people) {
        List<Person> tmp = one.filter(people);
        return other.filter(tmp);
    }
}
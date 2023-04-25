package yitian.study.filter;

public class Person {
    private int age;
    private String name;
    private Gender gender;

    @Override
    public String toString() {
        final StringBuilder sb = new StringBuilder("Person{");
        sb.append("age=").append(age);
        sb.append(", name='").append(name).append('\'');
        sb.append(", gender=").append(gender);
        sb.append('}');
        return sb.toString();
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Gender getGender() {
        return gender;
    }

    public void setGender(Gender gender) {
        this.gender = gender;
    }

    public Person(int age, String name, Gender gender) {

        this.age = age;
        this.name = name;
        this.gender = gender;
    }
}

enum Gender {
    Male, Female
}
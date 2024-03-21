package tech.techstay.generic;

import java.util.*;

public class Variance {
  public static void main(String[] args) {
    invariance();
    covariance();
    contravariance();
    varianceOfCollections();
  }

  static void invariance() {
    Businessman<Animal> animalBusinessman = new Businessman<>();
    animalBusinessman.buy(new Animal());
    Animal animal = animalBusinessman.sell();

    Businessman<Cat> catBusinessman = new Businessman<>();
    catBusinessman.buy(new Cat());
    Cat cat = catBusinessman.sell();

    if (Objects.nonNull(animal) && Objects.nonNull(cat)) {
      System.out.println("invariance success");
    } else {
      throw new RuntimeException("invariance failed");
    }
  }

  static void covariance() {
    Businessman<? extends Animal> businessman = new Businessman<Cat>(List.of(new Cat(), new Cat()));
    Animal animal = businessman.sell();

    // 这个商人什么也买不了
    // businessman.buy(new Animal());

    if (Objects.nonNull(animal)) {
      System.out.println("covariance success");
    } else {
      throw new RuntimeException("covariance failed");
    }

  }

  static void contravariance() {
    Cat catForSale = new Cat();
    Businessman<? super Cat> catBusinessman = new Businessman<Animal>();
    catBusinessman.buy(catForSale);

    // 这个商人只能卖出去东西
    Object c = catBusinessman.sell();

    if (catBusinessman.inventory.isEmpty()) {
      System.out.println("contravariance success");
    } else {
      throw new RuntimeException("contravariance failed");
    }
  }

  @SuppressWarnings("unused")
  static void varianceOfCollections() {
    // arrays
    try {
      Animal[] animals = new Dog[3];
      animals[0] = new Dog();
      animals[1] = new Dog();
      // type mismatch, will cause exceptions
      animals[2] = new Cat();
    } catch (ArrayStoreException e) {
      System.err.println("the cat cannot be added to dog arrays");
    }

    // covariance
    List<? extends Animal> animals = List.of(new Cat(), new Cat());
    Animal animal1 = animals.get(0);

    // 会报错，只能读不能写
    // animals.add(new Cat());

    // contravariance
    List<? super Cat> cats = new ArrayList<Animal>();
    cats.add(new Cat());
    cats.add(new Cat());

    // 只能读取到Object
    Object o = cats.get(0);

  }
}


class Animal {
}


class Dog extends Animal {
}


class Cat extends Animal {
}


class Businessman<T> {
  public final LinkedList<T> inventory = new LinkedList<>();

  public Businessman() {}

  public Businessman(Collection<T> collection) {
    inventory.addAll(collection);
  }

  public void buy(T t) {
    inventory.push(t);
  }

  public T sell() {
    return inventory.pop();
  }
}

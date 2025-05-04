package tech.techstay.generic;

import java.util.*;

public class VarianceDemo {
  public static void main(String[] args) {
    invariance();
    covariance();
    contravariance();
    varianceOfCollections();
  }

  static void invariance() {
    Merchant<Animal> animalMerchant = new Merchant<>();
    animalMerchant.buy(new Animal());
    Animal animal = animalMerchant.sell();

    Merchant<Cat> catMerchant = new Merchant<>();
    catMerchant.buy(new Cat());
    Cat cat = catMerchant.sell();

    if (Objects.nonNull(animal) && Objects.nonNull(cat)) {
      System.out.println("invariance success");
    } else {
      throw new RuntimeException("invariance failed");
    }
  }

  static void covariance() {
    Merchant<? extends Animal> businessman = new Merchant<Cat>(List.of(new Cat(), new Cat()));
    Animal animal = businessman.sell();

    // This merchant can buy nothing
    // businessman.buy(new Cat());

    if (Objects.nonNull(animal)) {
      System.out.println("covariance success");
    } else {
      throw new RuntimeException("covariance failed");
    }

  }

  static void contravariance() {
    Cat catForSale = new Cat();
    Merchant<? super Cat> catMerchant = new Merchant<Animal>();
    catMerchant.buy(catForSale);

    // The merchant can only sell goods
    Object c = catMerchant.sell();

    if (catMerchant.inventory.isEmpty()) {
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
      // type mismatch, it will cause exceptions
      animals[2] = new Cat();
    } catch (ArrayStoreException e) {
      System.err.println("the cat cannot be added to dog arrays");
    }

    // covariance
    List<? extends Animal> animals = List.of(new Cat(), new Cat());
    Animal animal1 = animals.get(0);

    // fails, can only read but not write
    // animals.add(new Cat());

    // contravariance
    List<? super Cat> cats = new ArrayList<Animal>();
    cats.add(new Cat());
    cats.add(new Cat());

    // Only get object type
    Object o = cats.get(0);

  }
}


class Animal {
}


class Dog extends Animal {
}


class Cat extends Animal {
}


class Merchant<T> {
  public final Deque<T> inventory;

  public Merchant() {
    this.inventory = new ArrayDeque<>();
  }

  public Merchant(Collection<T> collection) {
    this.inventory = new ArrayDeque<>(collection);
  }

  public void buy(T t) {
    inventory.push(t);
  }

  public T sell() {
    return inventory.pop();
  }
}

struct Animal;

trait Dog {
    fn speak(&self);
    fn walk();
}

trait Cat {
    fn speak(&self);
    fn walk();
}

impl Animal {
    fn speak(&self) {
        println!("animal speaks");
    }
    fn walk() {
        println!("animal walks");
    }
}

impl Dog for Animal {
    fn speak(&self) {
        println!("dog barks");
    }

    fn walk() {
        println!("dog walks");
    }
}

impl Cat for Animal {
    fn speak(&self) {
        println!("cat meows");
    }

    fn walk() {
        println!("cat walks");
    }
}

fn main() {
    let animal = Animal {};

    // explicit syntax to call method with the same name
    animal.speak();
    Dog::speak(&animal);
    Cat::speak(&animal);

    // using full-qualified names to distinguish between functions
    Animal::walk();
    <Animal as Dog>::walk();
    <Animal as Cat>::walk();
}

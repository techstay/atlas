trait Animal {
    fn walk(&self);
    fn speak(&self);
}

struct Dog {
    name: String,
}

struct Cat {
    name: String,
}

impl Animal for Dog {
    fn walk(&self) {
        println!("dog {} walks", self.name);
    }
    fn speak(&self) {
        println!("dog {} barks", self.name);
    }
}

impl Animal for Cat {
    fn walk(&self) {
        println!("cat {} walks", self.name);
    }
    fn speak(&self) {
        println!("cat {} meows", self.name);
    }
}

fn main() {
    let mut animals: Vec<Box<dyn Animal>> = vec![
        Box::new(Dog {
            name: String::from("Jerry"),
        }),
        Box::new(Cat {
            name: String::from("Tom"),
        }),
        Box::new(Dog {
            name: String::from("Buddy"),
        }),
    ];

    animals.push(Box::new(Cat {
        name: String::from("Mimi"),
    }));

    // for animal in &animals {
    //     animal.speak();
    //     animal.walk();
    // }

    animals.iter().for_each(|e| {
        e.walk();
        e.speak();
    });
}

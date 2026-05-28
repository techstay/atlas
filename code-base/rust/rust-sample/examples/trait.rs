use std::fmt::{Debug, Display};

#[derive(Debug)]
struct Contact {
    name: String,
    phone: String,
}

trait Callable {
    fn call(&self);
    // default implementation
    fn emergency_call(&self) {
        println!("call emergency: 911");
    }
}

impl Callable for Contact {
    fn call(&self) {
        println!("call {}: {}", self.name, self.phone);
    }
}

// traits as arguments
fn _foo(_c: &impl Callable) {}

fn _zoo<T, U>(_x: &T, _y: &U)
where
    T: Callable + Display,
    U: Callable + Debug,
{
}

// traits as return values
fn _bar() -> impl Callable {
    Contact {
        name: String::new(),
        phone: String::new(),
    }
}
fn main() {
    let contact = Contact {
        name: "jack".to_string(),
        phone: "123456789".to_string(),
    };

    contact.call();
    contact.emergency_call();
}

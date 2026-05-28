use std::{
    cell::RefCell,
    rc::{Rc, Weak},
};

fn box_pointer() {
    // creating pointers
    let x = String::from("x");
    let mut box_x = Box::new(x);

    box_x.push('y');
    println!("box x = {}", box_x);

    {
        let mut box_x2 = box_x;
        box_x2.push('z');
        println!("box x2 = {}", box_x2);
    }
}

fn ref_pointer() {
    // creating pointers
    let x = String::from("x");
    let ref_x = Rc::new(x);

    // printing ref count
    println!("ref count: {}", Rc::strong_count(&ref_x));
    {
        let ref_x2 = Rc::clone(&ref_x);
        println!("ref count: {}", Rc::strong_count(&ref_x2));
    }

    println!("ref count: {}", Rc::strong_count(&ref_x));
}

fn ref_cell_pointer() {
    // creating pointers
    let x = String::from("x");
    let ref_x = RefCell::new(x);

    {
        // immutable ref operates mutable data!
        ref_x.borrow_mut().push('y');
        println!("ref x = {}", ref_x.borrow());
    }

    println!("ref x = {}", ref_x.borrow());
}

fn weak_pointer() {
    // creating pointers
    let x = String::from("xyz");
    let ref_x = Rc::new(x);

    let test_pointer = |x: &Weak<String>| match x.upgrade() {
        Some(strong_x) => println!("strong ref x = {}", strong_x),
        None => println!("the pointer has gone"),
    };

    // printing ref count
    println!("ref count: {}", Rc::strong_count(&ref_x));

    let weak_x = Rc::downgrade(&ref_x);
    {
        println!("weak ref count: {}", Rc::weak_count(&ref_x));
        println!("ref count: {}", Rc::strong_count(&ref_x));
    }

    test_pointer(&weak_x);
    drop(ref_x);
    test_pointer(&weak_x);
}

fn main() {
    println!("box pointer:");
    box_pointer();
    println!("\nref pointer:");
    ref_pointer();
    println!("\nref cell pointer:");
    ref_cell_pointer();
    println!("\nweak pointer:");
    weak_pointer();
}

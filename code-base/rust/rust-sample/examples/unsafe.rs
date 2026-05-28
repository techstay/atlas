static mut HELLO_WORLD: &str = "hello world";

union Number {
    integer: i32,
    float: f64,
    byte: i8,
}

fn main() {
    // accessing and changing mutable global variables
    unsafe {
        println!("{}", HELLO_WORLD);
        HELLO_WORLD = "HELLO WORLD";
        println!("{}", HELLO_WORLD);
    }

    // using unions
    let mut number = Number { integer: 32 };

    unsafe {
        println!("{}", number.integer);
        println!("{}", number.byte);
    }

    number = Number { float: 2.7 };
    unsafe {
        println!("{}", number.float);
    }
}

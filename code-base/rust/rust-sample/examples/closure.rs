fn accept_closure(f: fn(i32) -> i32, x: i32) {
    println!("{}", f(x));
}

fn multiply_by_two(x: i32) -> i32 {
    x * 2
}

fn main() {
    // some closures
    let double = |x: i32| x * 2;
    let double_v2 = |x: i32| {
        // closure blocks
        x * 2
    };

    let double_v3 = |x: i32| -> i32 { x * 2 };
    let print_something = || println!("something");

    println!("{}", double(2));
    println!("{}", double_v2(2));
    println!("{}", double_v3(2));
    print_something();

    accept_closure(|x| x * 2, 4);
    accept_closure(double, 4);
    accept_closure(multiply_by_two, 4);
}

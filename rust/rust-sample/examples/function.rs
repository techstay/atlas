fn main() {
    let str = foo();
    println!("str is {str}");

    let int = bar();
    println!("int is {int}");

    let x = 5;
    let x = double(x);
    println!("double x is {x}");
}

fn foo() -> String {
    String::from("foo")
}
fn bar() -> i32 {
    42
}

fn double(x: i32) -> i32 {
    x * 2
}

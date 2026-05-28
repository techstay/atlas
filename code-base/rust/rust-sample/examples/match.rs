fn main() {
    let some_int = Some(58);
    match some_int {
        Some(x) => println!("I get the number: {x}"),
        None => println!("no value"),
    };

    // single match
    if let Some(x) = some_int {
        println!("I get the number: {x}");
    } else {
        println!("no value");
    }
}

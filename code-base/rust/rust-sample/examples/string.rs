fn main() {
    // creating
    let mut str1 = String::new();
    let mut str2 = String::from("Hello");

    // pushing
    str1.push_str("Hello");
    str2.push_str(" world");

    str1.push('.');

    // concatenating
    let hello = String::from("Hello");
    let world = String::from(" world");
    // after concatenating, the above `hello` string is invalid and should't be used
    let hello_world = hello + &world;
    println!("{}", hello_world);

    let hello_world = format!("{}-{}!", "Hello", &world[1..]);
    println!("{}", hello_world);
}

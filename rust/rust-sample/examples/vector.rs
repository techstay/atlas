fn main() {
    // creating
    let mut v1: Vec<i32> = Vec::new();
    let mut v2 = vec![1, 2, 3];

    // adding elements
    v1.push(2);
    v1.push(3);

    v1.insert(1, 30);

    println!("{:?}", v1);

    // iterating
    for i in &v1 {
        print!("{i} ");
    }
    println!();

    // mutable iterating
    for i in &mut v2 {
        *i += 10;
        print!("{i} ");
    }
    println!();
}

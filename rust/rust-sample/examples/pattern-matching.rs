fn main() {
    // matching
    let x = 5;
    match x {
        1 | 2 | 3 => println!("{} is less than 4", x),
        4..=10 if x % 2 == 0 => println!("{} is between 4 and 10 and is even", x),
        _ => println!("{} is something else", x),
    }

    let x = Some(5);

    // if matching
    if let Some(x) = x {
        println!("{}", x);
    } else {
        println!("None");
    }

    // while matching
    let mut stack = vec![1, 2, 3, 4, 5];
    while let Some(x) = stack.pop() {
        print!("{} ", x);
    }
    println!();

    // for iteration
    let list = vec![1, 2, 3, 4, 5];
    for (index, value) in list.iter().enumerate() {
        println!("{} {}", index, value);
    }

    // let matching
    let (x, y, z) = (1, 2, 3);
    println!("{} {} {}", x, y, z);
}

fn main() {
    // if else
    let i = 2;
    if i <= 10 {
        println!("{i} <= 5");
    } else {
        println!("{i} > 5");
    }

    // if else if
    if i == 1 {
        println!("one");
    } else if i == 2 {
        println!("two");
    } else if i == 3 {
        println!("three");
    }

    let if_i_eq_3 = if i == 3 { "true" } else { "false" };
    println!("{if_i_eq_3}");
}

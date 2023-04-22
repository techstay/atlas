fn main() {
    // break
    let mut i = 0;
    while i < 10 {
        i += 1;
        if i == 5 {
            break;
        }
        print!("{i} ");
    }

    println!();

    // continue
    i = 0;
    while i < 10 {
        i += 1;
        if i == 5 {
            continue;
        }
        print!("{i} ");
    }

    println!();
}

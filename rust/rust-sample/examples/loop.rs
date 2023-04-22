fn main() {
    // infinite loop
    let mut i = 0;
    loop {
        i += 1;
        if i == 10 {
            break;
        }
    }
    println!("out of loop");

    i = 0;
    // label
    'outer_loop: loop {
        i += 1;
        'inner_loop: loop {
            i += 1;
            if i == 20 {
                break 'inner_loop;
            }
            if i == 10 {
                break 'outer_loop;
            }
        }
    }
    println!("out of loop");
}

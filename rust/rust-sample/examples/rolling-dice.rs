use rand::prelude::*;
use std::collections::HashMap;

fn main() {
    let mut rolling_dice: HashMap<i32, i32> = HashMap::new();
    let n = 500_000;
    for _ in 1..=n {
        let rand = rand::thread_rng().gen_range(1..=6);
        let count = rolling_dice.entry(rand).or_insert(0);
        *count += 1;
    }

    println!("{:?}", rolling_dice);
}

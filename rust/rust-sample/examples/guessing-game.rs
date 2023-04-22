use rand::prelude::*;
use std::cmp::Ordering;
use std::io::{self, Write};

fn main() {
    let secret_number = rand::thread_rng().gen_range(1..=10);

    loop {
        print!("Please input your guess(1-10): ");
        io::stdout().flush().expect("Failed to flush output");

        let mut guess = String::new();

        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read line");

        let guess: i32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("Invalid input, please try again!");
                continue;
            }
        };

        println!("You guessed: {guess}");

        match guess.cmp(&secret_number) {
            Ordering::Less => println!("Too small!"),
            Ordering::Greater => println!("Too big!"),
            Ordering::Equal => {
                println!("You win!");
                break;
            }
        }
    }
}

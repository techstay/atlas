use std::{thread, time::Duration};

fn main() {
    // creating threads
    let handle = thread::spawn(|| {
        for i in 1..=5 {
            println!("print something in sub thread {}", i);
            thread::sleep(Duration::from_millis(200));
        }
    });

    // main threads
    for i in 1..=3 {
        println!("print something in main thread: {i}");
        thread::sleep(Duration::from_millis(200));
    }

    handle.join().unwrap();
}

use std::{sync::mpsc, thread, time::Duration};

fn channel() {
    let (tx, rx) = mpsc::channel();

    thread::spawn(move || {
        let str = String::from("hello");
        tx.send(str).unwrap();
    });

    let received = rx.recv().unwrap();
    println!("received: {}", received);
}

fn channel2() {
    let (tx, rx) = mpsc::channel();

    thread::spawn(move || {
        let messages = vec![
            String::from("hello"),
            String::from("world"),
            String::from("hi"),
        ];
        for msg in messages {
            tx.send(msg).unwrap();
            thread::sleep(Duration::from_secs(1));
        }
    });

    for received in rx {
        println!("received: {}", received);
    }
}

fn main() {
    channel();
    channel2();
}

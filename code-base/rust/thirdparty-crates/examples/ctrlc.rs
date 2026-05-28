use std::{
    process::{self},
    thread,
    time::Duration,
};

// ctrlc is a crate that allows you to catch Ctrl-C events.
fn main() {
    ctrlc::set_handler(move || {
        println!("received Ctrl+C!");
        // exit the program
        process::exit(exitcode::OK);
    })
    .expect("Error setting Ctrl-C handler");

    // Following code does the actual work, and can be interrupted by pressing
    // Ctrl-C. As an example: Let's wait a few seconds.
    thread::sleep(Duration::from_secs(2));
}

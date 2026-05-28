use std::thread;
use std::time::Duration;

use indicatif::{MultiProgress, ProgressBar, ProgressStyle};
use rand::prelude::*;

fn finebars() {
    let styles = [
        ("Rough bar:", "█  ", "red"),
        ("Fine bar: ", "█▉▊▋▌▍▎▏  ", "yellow"),
        ("Vertical: ", "█▇▆▅▄▃▂▁  ", "green"),
        ("Fade in:  ", "█▓▒░  ", "blue"),
        ("Blocky:   ", "█▛▌▖  ", "magenta"),
    ];

    let m = MultiProgress::new();

    let handles: Vec<_> = styles
        .iter()
        .map(|s| {
            let len = 512;
            let pb = m.add(ProgressBar::new(len));
            pb.set_style(
                ProgressStyle::with_template(&format!("{{prefix:.bold}}▕{{bar:.{}}}▏{{msg}}", s.2))
                    .unwrap()
                    .progress_chars(s.1),
            );

            pb.set_prefix(s.0);
            thread::spawn(move || {
                for i in 0..len {
                    thread::sleep(Duration::from_millis(thread_rng().gen_range(5..20)));
                    pb.inc(1);
                    pb.set_message(format!("{:3}%", 100 * i / len));
                }
                pb.finish_with_message("100%");
            })
        })
        .collect();

    for h in handles {
        let _ = h.join();
    }
}

fn single() {
    let length = 512;
    let pb = ProgressBar::new(length);
    for _ in 0..length {
        thread::sleep(Duration::from_millis(5));
        pb.inc(1);
    }
    pb.finish_with_message("done");
}

fn main() {
    single();
    finebars();
}

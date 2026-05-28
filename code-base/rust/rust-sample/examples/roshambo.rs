fn main() {
    // roshambo game
    let mut a = Roshambo::Rock;
    let mut b = Roshambo::Paper;

    let mut result = play_roshambo_game(&a, &b);
    println!("{:?} vs {:?}, win?: {}", a, b, result);

    a = Roshambo::Scissors;
    b = Roshambo::Paper;

    result = play_roshambo_game(&a, &b);
    println!("{:?} vs {:?}, win?: {}", a, b, result);
}

#[derive(Debug)]
enum Roshambo {
    Rock,
    Paper,
    Scissors,
}

fn play_roshambo_game(a: &Roshambo, b: &Roshambo) -> bool {
    match (a, b) {
        (Roshambo::Rock, Roshambo::Paper) => false,
        (Roshambo::Rock, Roshambo::Scissors) => true,
        (Roshambo::Paper, Roshambo::Rock) => true,
        (Roshambo::Paper, Roshambo::Scissors) => false,
        (Roshambo::Scissors, Roshambo::Rock) => false,
        (Roshambo::Scissors, Roshambo::Paper) => true,
        _ => false,
    }
}

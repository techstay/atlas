#[derive(Debug)]
struct Point<T> {
    x: T,
    y: T,
}

impl<T> Point<T> {
    fn new_point(x: T, y: T) -> Point<T> {
        Point { x, y }
    }
}

fn main() {
    let p = Point::new_point(1, 2);
    println!("{:?}", p);

    let p2 = Point::new_point(5.0, 6.0);
    println!("{:?}", p2);

    let x = p2.x;
    let y = p2.y;
    println!("x = {}, y = {}", x, y);
}

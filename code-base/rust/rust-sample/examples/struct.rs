#[derive(Debug)]
struct Rectangle {
    height: f64,
    width: f64,
}

impl Rectangle {
    fn area(&self) -> f64 {
        self.height * self.width
    }
    fn square(size: f64) -> Self {
        Self {
            height: size,
            width: size,
        }
    }
}

fn main() {
    let rectangle = Rectangle {
        height: 4.0,
        width: 3.0,
    };
    println!("{:#?}", rectangle);
    println!("area: {}", rectangle.area());
    println!("square: {:?}", Rectangle::square(2.0));
}

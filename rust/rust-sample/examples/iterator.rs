fn main() {
    immutable_iterator();
    mutable_iterator();
    stream_operation();
}

fn immutable_iterator() {
    let vec1 = vec![1, 2, 3, 4, 5, 6, 7];

    // iterators
    let iter = vec1.iter();
    for x in iter {
        print!("{} ", x);
    }

    println!();
}

fn mutable_iterator() {
    let mut vec1 = vec![1, 2, 3, 4, 5, 6, 7];

    let mut iter = vec1.iter_mut();
    while let Some(x) = iter.next() {
        *x += 1;
    }

    println!("{:?}", vec1);
}
fn stream_operation() {
    let vec1 = vec![1, 2, 3, 4, 5, 6, 7];

    let vec2: Vec<i32> = vec1
        .iter()
        .filter(|&x| x % 2 != 0)
        .map(|&x| x * x)
        .collect();

    println!("{:?}", vec2);
}

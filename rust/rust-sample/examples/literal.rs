use std::f64;

fn main() {
    // integer types:
    // i8 to i128 for signed integers
    // and u8 to u128 for unsigned integers

    let _int8: i8 = 8;

    // float types: f32 and f64
    let _pi: f64 = 3.1;
    let _pi: f64 = f64::consts::PI;

    // other-based numbers
    let _hex = 0xcafe;
    let _octal = 0o12345;
    let _binary = 0b1010_1100;

    // byte, only compatible with u8
    let _byte = b'a';

    // bool
    let _truth = true;
    let _lie = false;

    // char
    let _char = 'a';

    // tuple
    let _tuple: (i32, i32, f64) = (1, 42, 3.1);

    // array
    let _array: [i32; 5] = [1, 2, 3, 4, 5];
}

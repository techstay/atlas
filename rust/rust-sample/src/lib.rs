//! # Rust Sample
//! My first Rust application.
//!
//! This project contains my rust sample code files.
//!
pub mod my_lib {
    use std::ops::{Add, Div, Mul, Rem, Sub};
    /// Calculates arguments using given operator
    ///
    /// # Examples
    /// ```
    /// use crate::rust_sample::my_lib::calculate;
    /// let a = 5;
    /// let b = 6;
    /// let c = calculate(a, b, '+');
    /// ```
    pub fn calculate<T>(x: T, y: T, op: char) -> T
    where
        T: Add<Output = T> + Sub<Output = T> + Mul<Output = T> + Div<Output = T> + Rem<Output = T>,
    {
        match op {
            '+' => x + y,
            '-' => x - y,
            '*' => x * y,
            '/' => x / y,
            '%' => x % y,
            _ => panic!("Invalid operator: {op}"),
        }
    }
}

#[cfg(test)]
mod tests {
    // use crate::my_lib::calculate;
    use super::my_lib::*;

    #[test]
    fn test_calculate() {
        assert_eq!(calculate(6, 4, '+'), 10);
        assert_eq!(calculate(6, 4, '-'), 2);
        assert_eq!(calculate(6, 4, '*'), 24);
        assert_eq!(calculate(6, 4, '/'), 1);
        assert_eq!(calculate(6.0, 4.0, '/'), 1.5);
        assert_eq!(calculate(6, 4, '%'), 2);
    }

    #[test]
    #[should_panic]
    fn test_calculate_panic() {
        calculate(6, 4, '&');
    }
}

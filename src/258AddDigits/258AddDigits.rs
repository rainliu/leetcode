impl Solution {
    pub fn add_digits(num: i32) -> i32 {
        num-9*((num-1)/9)
    }
}

impl Solution {
    pub fn trailing_zeroes(n: i32) -> i32 {
        if n<=0 {0} else {n/5+Self::trailing_zeroes(n/5)}
    }
}

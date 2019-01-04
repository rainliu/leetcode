impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 {
            return false;
        }
        let mut n = 0;
        let mut y = x;
        let mut d = 0;
        while y != 0 {
            n += 1;
            y /= 10;
            d = if d == 0 {1} else {d*10};
        }
        y = x;
        while n > 1 && y != 0 {
            if y % 10 != y / d {
                return false;
            }
            y -= (y/d)*d;
            y /= 10;
            n -= 2;
            d /= 100;
        }
        true
    }
}

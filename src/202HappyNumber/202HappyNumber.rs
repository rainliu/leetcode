impl Solution {
    pub fn is_happy(n: i32) -> bool {
        let mut s = std::collections::HashSet::new();
        let mut m = n;
        while !s.contains(&m) {
            s.insert(m);
            m = Self::sum_of_square(m);
            if m == 1 {
                return true;
            }
        }
        false
    }
    fn sum_of_square(n: i32) -> i32{
        let mut m = n;
        let mut sum = 0;
        while m!= 0 {
            let d = m%10;
            m = m/10;
            sum += d*d;
        }
        sum
    }
}

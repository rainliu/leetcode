impl Solution {
    pub fn plus_one(digits: Vec<i32>) -> Vec<i32> {
        let mut iter = digits.into_iter().rev();
        let mut c = 1;
        let mut result = Vec::new();
        while let Some(d) = iter.next() {
            let e = d + c;
            result.push(e % 10);
            c = e /10;
        }
        if c > 0 {
            result.push(c);
        }
        result.into_iter().rev().collect()
    }
}

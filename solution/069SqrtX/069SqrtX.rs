impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        if x <= 1 {return x;}
        let mut lo = 1;
        let mut hi = x/2;
        while lo<=hi {
            let mut mi = lo + (hi-lo)/2;
            let t = x/mi;
            if mi == t {
                return mi;
            }else if mi > t {
                hi = mi - 1;
            }else{
                lo = mi + 1;
            }
        }
        hi
    }
}
